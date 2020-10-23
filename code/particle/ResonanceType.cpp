#include "ResonanceType.hpp"

ResonanceType::ResonanceType(ParticleType particle_t, double width)
    : ParticleType{particle_t}, fWidth{width} {}

double ResonanceType::getWidth() { return fWidth; }

void ResonanceType::Print() {
  std::cout << "Name: " << fName << '\n';
  std::cout << "Mass: " << fMass << '\n';
  std::cout << "Charge: " << fCharge << '\n';
  std::cout << "Resonance: " << fWidth << '\n';
  std::cout << '\n';
}