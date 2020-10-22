#include "Particle.hpp"

Particle::Particle(std::vector<ParticleType*> particle_v, std::string name, P p) : fParticleType{particle_v}, fName{name}, fP{p} {
    ParticleType* result = FindParticle(particle_v);
    if (result != nullptr) {
        std::cout << "Find " << result -> getName() << ' ' << "at the " << fNParticleType << "-th " << "position" << '\n';
    } else {
        std::cout << "Not Find" << '\n';
    }
}

P Particle::getP() { return fP; }

void Particle::setP(double const& px, double const& py, double const& pz) {
    fP.fPx = px;
    fP.fPy = py;
    fP.fPz = pz;
}

double Particle::Energy() {
    auto p = FindParticle(fParticleType);
    double m = p -> getMass();
    double lm_x = fP.fPx;
    double lm_y = fP.fPy;
    double lm_z = fP.fPz;
    double E = std::sqrt( (m * m) + (lm_x * lm_x) + (lm_y * lm_y) + (lm_z * lm_z) );
    return E;
}