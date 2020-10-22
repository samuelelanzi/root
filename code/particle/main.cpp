#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include "Particle.hpp"

int main() {
    ParticleType* electron = new ParticleType {"electron", 9.109e-31, -1};
    ResonanceType* e_resonance = new ResonanceType {*electron, 0.};
    ParticleType* proton = new ParticleType {"proton", 1.673e-27, 1};
    ResonanceType* p_resonance = new ResonanceType {*proton, 0.};
    ParticleType* neutron = new ParticleType {"neutron", 1.675e-27, 0};
    ResonanceType* n_resonance = new ResonanceType {*neutron, 0.};

    std::vector<ParticleType*> particle_v {};

    particle_v.push_back(electron);
    // particle_v.push_back(e_resonance);
    particle_v.push_back(proton);
    // particle_v.push_back(p_resonance);
    particle_v.push_back(neutron);
    // particle_v.push_back(n_resonance);

    for(auto i : particle_v) {
        i -> Print();
    }

    P l_momentum {2.4, 4.8, 0.};
    Particle par {particle_v, "electron", l_momentum};
}
