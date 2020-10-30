#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "invMass.hpp"
#include "TRandom.h"
#include "rndmCharge.hpp"
#include <random>

int main() {
  std::vector<ParticleType*> particle_v{};

  // Particle e{particle_v, "electron", e_linearMomentum, 0};
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1,100);
  int seed = distrib(gen);
  
  gRandom->SetSeed(seed);

  for(int i = 0; i != 10e5; ++i) {
    for(int j = 0; j != 10e2; ++j) {
      int prob_type = distrib(gen);
      int charge = rndmCharge(prob_type);

      auto phi = gRandom->Uniform(0., 2 * M_PI);
      auto theta = gRandom->Uniform(0., M_PI);
      auto p_ = gRandom->Exp(1);

      if (prob_type <= 80) {
        ParticleType* pion = new ParticleType {"pion", 0.13957, charge};
        particle_v.push_back(pion);
      } else if (prob_type > 80 && prob_type <= 90) {
        ParticleType* kaon = new ParticleType {"kaon", 0.49367, charge};
        particle_v.push_back(kaon);
      } else if (prob_type > 90 && prob_type <= 99) {
        ParticleType* proton = new ParticleType {"proton", 0.93827, charge};
        particle_v.push_back(proton);
      } else {
        ParticleType* K_s = new ParticleType {"K*", 0.89166, 0};
        ResonanceType* K_resonance = new ResonanceType {*K_s, 0.050};
        particle_v.push_back(K_s);
      }
    }
  }
}