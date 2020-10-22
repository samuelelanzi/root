#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "ParticleType.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

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
    int fNParticleType = 0;

    ParticleType* FindParticle(std::vector<ParticleType*> const& particle_v) {
        for(auto i : particle_v) {
            ++fNParticleType;
            auto result = i -> getName() == fName;
            if(result) {
                return i;
            } 
        }
    }

public:
    Particle(std::vector<ParticleType*> particle_v, std::string name, P p);
    P getP();
    void setP(double const& px, double const& py, double const& pz);
    ParticleType* AddParticleType(std::string const& name, double const& mass, int const& charge, int const& width);
    double Energy();
};

#endif