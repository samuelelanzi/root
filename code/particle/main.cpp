#include "ParticleType.hpp"
#include "ResonanceType.hpp"

int main() { 
    ParticleType particle {"electron", 9.109e-31, -1};
    particle.print();
    
    ResonanceType resonance {particle.getName(), particle.getMass(), particle.getCharge(), 23.78};
    resonance.print();
}
