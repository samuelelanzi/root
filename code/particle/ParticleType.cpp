#include "ParticleType.hpp"

ParticleType::ParticleType(std::string name, double mass, int charge)
    : fName{name}, fMass{mass}, fCharge{charge} {}

std::string ParticleType::getName() { return fName; }

double ParticleType::getMass() { return fMass; }

int ParticleType::getCharge() { return fCharge; }

void ParticleType::setCharge(int &charge) {
  fCharge = charge;
}

double ParticleType::getWidth() { return 0.; }

void ParticleType::Print() {
  std::cout << "Name: " << fName << '\n';
  std::cout << "Mass: " << fMass << '\n';
  std::cout << "Charge: " << fCharge << '\n';
  std::cout << '\n';
}