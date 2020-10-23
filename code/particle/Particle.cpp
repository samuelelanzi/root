#include "Particle.hpp"

ParticleType *
Particle::FindParticle(std::vector<ParticleType *> const &particle_v) {
  for (auto i : particle_v) {
    ++fNParticleType;
    auto result = i->getName() == fName;
    if (result) {
      return i;
    }
  }
}

Particle::Particle(std::vector<ParticleType *> particle_v, std::string name,
                   P p, int i)
    : fParticleType{particle_v}, fName{name}, fP{p}, fIParticle{i} {
  ParticleType *result = FindParticle(particle_v);
  if (result != nullptr) {
    std::cout << "Find " << result->getName() << ' ' << "at the "
              << fNParticleType << "-th "
              << "position" << '\n';
  } else {
    std::cout << "Not Find" << '\n';
  }
}

void Particle::printParticle() {
  auto p = FindParticle(fParticleType);
  std::cout << fNParticleType / 2 << " - " << p->getName() << '\n'
            << "P: (" << fP.fPx << ", " << fP.fPy << ", " << fP.fPz << ")\n\n";
}

double Particle::getParticleMass() {
  auto p = FindParticle(fParticleType);
  return p->getMass();
}

P Particle::getP() { return fP; }

void Particle::setP(double const &px, double const &py, double const &pz) {
  fP.fPx = px;
  fP.fPy = py;
  fP.fPz = pz;
}

int Particle::getIParticle() { return fIParticle; }

double Particle::Energy() {
  auto p = FindParticle(fParticleType);
  double m = p->getMass();
  double lm_x = fP.fPx;
  double lm_y = fP.fPy;
  double lm_z = fP.fPz;
  double E = std::sqrt((m * m) + (lm_x * lm_x) + (lm_y * lm_y) + (lm_z * lm_z));
  return E;
}

void Particle::Boost(double bx, double by, double bz) {

  double energy = Energy();

  double b2 = bx * bx + by * by + bz * bz;
  double gamma = 1.0 / std::sqrt(1.0 - b2);
  double bp = bx * fP.fPx + by * fP.fPy + bz * fP.fPz;
  double gamma2 = b2 > 0 ? (gamma - 1.0) / b2 : 0.0;

  fP.fPx += gamma2 * bp * bx + gamma * bx * energy;
  fP.fPy += gamma2 * bp * by + gamma * by * energy;
  fP.fPz += gamma2 * bp * bz + gamma * bz * energy;
}

int Particle::Decay2body(Particle &dau1, Particle &dau2) {
  if (getParticleMass() == 0.0) {
    std::cout << "Decayment cannot be preformed if mass is zero\n";
    return 1;
  }

  double massMot = getParticleMass();
  double massDau1 = dau1.getParticleMass();
  double massDau2 = dau2.getParticleMass();

  if (fIParticle > -1) {
    float x1, x2, w, y1, y2;

    double invnum = 1. / RAND_MAX;

    do {
      x1 = 2.0 * rand() * invnum - 1.0;
      x2 = 2.0 * rand() * invnum - 1.0;
      w = x1 * x1 + x2 * x2;
    } while (w >= 1.0);

    w = sqrt((-2.0 * std::log(w)) / w);
    y1 = x1 * w;
    y2 = x2 * w;

    massMot += fParticleType[fIParticle]->getWidth() * y1;
  }

  if (massMot < massDau1 + massDau2) {
    printf("Decayment cannot be preformed because mass is too low in this "
           "channel\n");
    return 2;
  }

  double pout =
      std::sqrt(
          (massMot * massMot - (massDau1 + massDau2) * (massDau1 + massDau2)) *
          (massMot * massMot - (massDau1 - massDau2) * (massDau1 - massDau2))) /
      massMot * 0.5;

  double norm = 2 * M_PI / RAND_MAX;

  double phi = rand() * norm;
  double theta = rand() * norm * 0.5 - M_PI / 2.;
  dau1.setP(pout * std::sin(theta) * std::cos(phi),
            pout * std::sin(theta) * std::sin(phi), pout * std::cos(theta));
  dau2.setP(-pout * std::sin(theta) * std::cos(phi),
            -pout * std::sin(theta) * std::sin(phi), -pout * std::cos(theta));

  double energy = std::sqrt(fP.fPx * fP.fPx + fP.fPy * fP.fPy +
                            fP.fPz * fP.fPz + massMot * massMot);

  double bx = fP.fPx / energy;
  double by = fP.fPy / energy;
  double bz = fP.fPz / energy;

  dau1.Boost(bx, by, bz);
  dau2.Boost(bx, by, bz);

  return 0;
}