#include "ResonanceType.hpp"

ResonanceType::ResonanceType(ParticleType const& particle, double width) : ParticleType{particle}, width_{width} {}

double ResonanceType::getWidth() { return width_; }

void ResonanceType::print() {
    std::cout << "width: " << width_ << '\n';
}