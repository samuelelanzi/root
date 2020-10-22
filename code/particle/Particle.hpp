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
    std::string fName;
    P fP;
    int fIParticle = 0;

    void FindParticle(std::vector<ParticleType*> const& particle_v) {
        for(auto i : particle_v) {
            ++fIParticle;
            auto result = i -> getName() == fName;
            if(result) {
                std::cout << "Find " << fName << ' ' << "at the " << fIParticle << "-th " << "position" << '\n';
            } else {
                std::cout << "Not Find" << '\n';
            }
        }
    }

public:
    Particle(std::vector<ParticleType*> particle_v, std::string name, P p);
    ParticleType* AddParticleType(std::string const& name, double const& mass, int const& charge, int const& width);
};

#endif