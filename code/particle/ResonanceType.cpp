#include "ResonanceType.hpp"

ResonanceType::ResonanceType(std::string name, double mass, int charge, double width) : ParticleType{name, mass, charge}, width_{width} {}

double ResonanceType::getWidth() { return width_; }

void ResonanceType::print() {
    std::cout << "width: " << width_ << '\n';
}