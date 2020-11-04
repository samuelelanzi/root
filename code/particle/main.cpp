#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "invMass.hpp"
#include "TRandom.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "rndmCharge.hpp"
#include <random>

int main() {
  std::vector<ParticleType*> particleT_v{};

  std::vector<double> phi_distribution{};
  std::vector<double> theta_distribution{};

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1,100);
  int seed = distrib(gen);
  
  gRandom->SetSeed(seed);

  for (int i = 0; i != 1e3; ++i) {
    for (int j = 0; j != 1e2; ++j) {
      int prob_type = distrib(gen);
      int charge = rndmCharge(prob_type);

      double phi = gRandom->Uniform(0., 2 * M_PI);
      phi_distribution.push_back(phi);
      double theta = gRandom->Uniform(0., M_PI);
      theta_distribution.push_back(theta);
      double p_ = gRandom->Exp(1);

      P pi_linearMomentum;
      P ka_linearMomentum;
      P pr_linearMomentum;
      P ks_linearMomentum;

      if (prob_type <= 80) {
        ParticleType* pion = new ParticleType {"pion", 0.13957, charge};
        particleT_v.push_back(pion);
        Particle pi {particleT_v, "pion", pi_linearMomentum};
        pi.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
      } else if (prob_type > 80 && prob_type <= 90) {
        ParticleType* kaon = new ParticleType {"kaon", 0.49367, charge};
        particleT_v.push_back(kaon);
        Particle ka {particleT_v, "kaon", ka_linearMomentum};
        ka.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
      } else if (prob_type > 90 && prob_type <= 99) {
        ParticleType* proton = new ParticleType {"proton", 0.93827, charge};
        particleT_v.push_back(proton);
        Particle pr {particleT_v, "proton", pr_linearMomentum};
        pr.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
      } else {
        ParticleType* K_s = new ParticleType {"K*", 0.89166, 0};
        ResonanceType* K_resonance = new ResonanceType {*K_s, 0.050};
        particleT_v.push_back(K_s);
        Particle ks {particleT_v, "K*", ka_linearMomentum};
        ks.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
      }      
    }
  }
  TCanvas* cAngles = new TCanvas ("cAngles", "Angles Distribution", 200, 100, 1100, 700);
  cAngles->Divide(1, 2);

  TH1F* hPhi = new TH1F("hPhi", "Phi Distribution", 1000, 0., 2 * M_PI);
  for (int i = 0; i != static_cast<int>(phi_distribution.size()); ++i) {
    hPhi->Fill(phi_distribution[i]);
  }

  TH1F* hTheta = new TH1F("hTheta", "Theta Distribution", 1000, 0., M_PI);
  for(int i = 0; i != static_cast<int>(theta_distribution.size()); ++i) {
    hTheta->Fill(theta_distribution[i]);
  }

  cAngles->cd(1);
  hPhi->Draw();

  cAngles->cd(2);
  hTheta->Draw();
}