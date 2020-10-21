#include "ParticleType.hpp"
#include "ResonanceType.hpp"

int main() {
    ParticleType particle {"electron", 9.1e-31, -1};
    particle.Print();
    ResonanceType resonance {particle, 0.};
    resonance.Print();
}
