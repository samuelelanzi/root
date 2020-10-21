#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include <vector>

int main() {
    ParticleType* particle = new ParticleType {"electron", 9.1e-31, -1};
    ResonanceType* resonance = new ResonanceType {*particle, 0.};

    std::vector<ParticleType*> particle_v {particle, resonance};

    for(auto i : particle_v) {
        i -> Print();
    }
}
