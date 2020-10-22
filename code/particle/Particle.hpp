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
    int fIParticle;
    P fP;
    std::string fName;

    void FindParticle(std::string const& name) {
        for(auto i : fParticleType) {
            bool result = i -> getName() == name;
            auto it = std::find_if(fParticleType.begin(), fParticleType.end(), [](bool result){
                return result;
            });
        }
    }
public:
    Particle(std::vector<ParticleType*> particle_v, P p);
};

#endif