#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "ParticleType.hpp"
#include <vector>
#include <algorithm>

struct P {
    double fPx = 0;
    double fPy = 0;
    double fPz = 0;
};

class Particle {
private:
    std::vector<ParticleType*> fParticleType;
    int fNParticleType;
    int fIParticle = 0;
    P fP;
    std::string fName;

    void FindParticle(std::vector<ParticleType*> const& particle_v) {
        for(auto i : particle_v) {
            auto result = i -> getName() == fName;
            if(result) {
                ++fIParticle;
                std::cout << "Find " << fName << ' ' << "at the " << fIParticle << "-th " << "position" << '\n';
            }
        }
    }

public:
    Particle(std::vector<ParticleType*> particle_v, std::string name, P p);
};

#endif