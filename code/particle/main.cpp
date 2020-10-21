#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include <vector>

int main() {
    ParticleType particle {"electron", 9.1e-31, -1};
  //  particle.Print();
    ResonanceType resonance {particle, 3.2};
    //resonance.Print();
    
    std::vector <ParticleType> ParticleV {particle, resonance};
    
    for (auto i: ParticleV){
        i.Print();
    }
}
