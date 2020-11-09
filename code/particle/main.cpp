#include "Particle.hpp"
#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "invMass.hpp"
#include "TRandom.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH1.h"
#include "TStyle.h"
#include "rndmCharge.hpp"
#include <random>

int main() {
  ParticleType* pion = new ParticleType {"pion", 0.13957, 0}; // 0 is default
  ParticleType* kaon = new ParticleType {"kaon", 0.49367, 0};
  ParticleType* proton = new ParticleType {"proton", 0.93827, 0};
  ParticleType* K_s = new ParticleType {"K*", 0.89166, 0};
  ResonanceType* K_resonance = new ResonanceType {*K_s, 0.050};

  std::vector<Particle> particle_v{};

  TH1F* hPhi = new TH1F("hPhi", "Phi Distribution", 100, 0., 2 * M_PI);
  TH1F* hTheta = new TH1F("hTheta", "Theta Distribution", 100, 0., M_PI);
  TH1F* hP = new TH1F("hP", "Momentum Distribution", 1000, 0, 7);
  TH1F* hPtr = new TH1F("hPtr", "Trasversal Momentum Distribution", 1000, 0, 5);
  TH1F* hE = new TH1F("hE", "Energy Distribution", 1000, 0, 6);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1,100);
  int seed = distrib(gen);
  
  gRandom->SetSeed(seed);

  for (int i = 0; i != 1e5; ++i) {
    for (int j = 0; j != 1e2; ++j) {
      int prob_type = distrib(gen);
      int charge = rndmCharge(prob_type);

      double phi = gRandom->Uniform(0., 2 * M_PI);
      hPhi->Fill(phi);
      double theta = gRandom->Uniform(0., M_PI);
      hTheta->Fill(theta);
      double p_ = gRandom->Exp(1);
      hP->Fill(p_);
      
      P pi_linearMomentum;
      P ka_linearMomentum;
      P pr_linearMomentum;
      P ks_linearMomentum;

      if (prob_type <= 80) 
      {
        pion->setCharge(charge);
        Particle pi {pion, "pion", pi_linearMomentum};
        pi.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
        hPtr->Fill(std::sqrt(std::pow(p_ * std::sin(theta) * std::cos(phi), 2) + std::pow(p_ * std::sin(theta) * std::sin(phi), 2)));
        hE->Fill(pi.Energy());
        particle_v.push_back(pi);
      } 

      else if (prob_type > 80 && prob_type <= 90) 
      {
        kaon->setCharge(charge);
        Particle ka {kaon, "kaon", ka_linearMomentum};
        ka.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
        hPtr->Fill(std::sqrt(std::pow(p_ * std::sin(theta) * std::cos(phi), 2) + std::pow(p_ * std::sin(theta) * std::sin(phi), 2)));
        hE->Fill(ka.Energy());
        particle_v.push_back(ka);
      } 

      else if (prob_type > 90 && prob_type <= 99) 
      {
        proton->setCharge(charge);
        Particle pr {proton, "proton", pr_linearMomentum};
        pr.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
        hPtr->Fill(std::sqrt(std::pow(p_ * std::sin(theta) * std::cos(phi), 2) + std::pow(p_ * std::sin(theta) * std::sin(phi), 2)));
        hE->Fill(pr.Energy());
        particle_v.push_back(pr);
      } 

      else 
      {
        Particle ks {K_s, "K*", ka_linearMomentum};
        ks.setP(p_ * std::sin(theta) * std::cos(phi), p_ * std::sin(theta) * std::sin(phi), p_ * std::cos(theta));
        hPtr->Fill(std::sqrt(std::pow(p_ * std::sin(theta) * std::cos(phi), 2) + std::pow(p_ * std::sin(theta) * std::sin(phi), 2)));
        hE->Fill(ks.Energy());
        particle_v.push_back(ks);
      }      
    }
  }

  for (auto i : particle_v) {
    if(i.getParticleType()->getName() == "K*") {
      //i.Decay2body(pi_d, ka_d);
      //particle_v.push_back(pi_d);
      //particle_v.push_back(ka_d);
      std::cout << "Found" << '\n';
    }
  }

  TCanvas* cPT = new TCanvas("cPT", "Particle Types Distribution", 100, 100, 1100, 700 );

  TH1F* hPT = new TH1F("hPT", "Particle Types Distribution", 4, 0, 5);
  for (int i = 0; i != static_cast<int>(particle_v.size()); ++i) {
    if (particle_v[i].getParticleType()->getName() == "pion") {
      hPT->Fill(1);
    } else if (particle_v[i].getParticleType()->getName() == "kaon") {
      hPT->Fill(2);
    } else if(particle_v[i].getParticleType()->getName() == "proton") {
      hPT->Fill(3);
    } else {
      hPT->Fill(4);
    }
  }
  hPT->Draw();

  TCanvas* cAngles = new TCanvas ("cAngles", "Angles Distribution", 200, 100, 1100, 700);
  cAngles->Divide(1, 2);

  cAngles->cd(1);
  hPhi->Fit("pol0");
  hPhi->Draw();

  cAngles->cd(2);
  hTheta->Fit("pol0");
  hTheta->Draw();

  TCanvas* cPE = new TCanvas("cPE", "Momentum & Energy", 300, 100, 1100, 700);
  cPE->Divide(1, 3);

  gStyle->SetOptStat(112210); 
  gStyle->SetOptFit(111);

  cPE->cd(1);
  hP->Fit("expo");
  hP->Draw();

  cPE->cd(2);
  hPtr->Draw();

  cPE->cd(3);
  hE->Draw(); 
}