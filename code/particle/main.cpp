#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "invMass.hpp"
#include "TRandom.h"
#include <random>

int main() {
  ParticleType *electron = new ParticleType{"electron", 9.109e-31, -1};
  // ResonanceType* e_resonance = new ResonanceType {*electron, 0.};
  ParticleType *proton = new ParticleType{"proton", 1.673e-27, 1};
  // ResonanceType* p_resonance = new ResonanceType {*proton, 0.};
  ParticleType *neutron = new ParticleType{"neutron", 1.675e-27, 0};
  // ResonanceType* n_resonance = new ResonanceType {*neutron, 0.};

  std::vector<ParticleType *> particle_v{};

  particle_v.push_back(electron);
  // particle_v.push_back(e_resonance);
  particle_v.push_back(proton);
  // particle_v.push_back(p_resonance);
  particle_v.push_back(neutron);
  // particle_v.push_back(n_resonance);

  for (auto i : particle_v) {
    i->Print();
  }

  P e_linearMomentum;
  P p_linearMomentum;
  P n_linearMomentum;

  Particle e{particle_v, "electron", e_linearMomentum, 0};
  Particle p{particle_v, "proton", p_linearMomentum, 1};
  Particle n{particle_v, "neutron", n_linearMomentum, 2};

  e.setP(1., 1., 1.);
  p.setP(2., 2., 2.);
  n.setP(1., 2., 1.);

  std::cout << '\n';

  e.printParticle();
  p.printParticle();
  n.printParticle();

  std::cout << "Electron Energy: " << e.Energy() << '\n';
  std::cout << "Proton Energy: " << p.Energy() << '\n';
  std::cout << "Neutron Energy: " << n.Energy() << '\n';

  // std::cout << e.getIParticle() << '\n';
  // std::cout << p.getIParticle() << '\n';
  // std::cout << n.getIParticle() << '\n';

  double invEP = invMass(e, p);
  std::cout << "\nMass invariant electron/proton: " << invEP << '\n';
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1,100);
  int seed = distrib(gen);
  


  gRandom->SetSeed(seed);

  for(int i = 0; i != 10e5; ++i) {
    for(int j = 0; j != 10e2; ++j) {
      int prob_type = distrib(gen);
      if (prob_type <= 80) {
          int charge;

          if(prob_type % 2 == 0){
            charge = 1;
          } else {
            charge = -1;
          }

          std::cout << charge;
      } else if (prob_type > 80 && prob_type <= 90) {

      } else if (prob_type > 90 && prob_type <= 99) {

      } else {

      }

      auto phi = gRandom->Uniform(0., 2 * M_PI);
      // std::cout << phi << '\n';
      auto theta = gRandom->Uniform(0., M_PI);
      // std::cout << theta << '\n';
      auto p_ = gRandom->Exp(1);
      // std::cout << p_ << '\n';

    }
  }

}