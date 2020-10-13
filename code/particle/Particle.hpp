#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "ParticleType.hpp"

class Particle {
private:
    static ParticleType* ParticleType_[];
    static int MaxNumParticleType_;
    static int NParticleType_;
    int IParticle_;
    double Px_;
    double Py_;
    double Pz_;
public:
    Particle(std::string name);
    ~Particle();
    int getIParticle();
};
#endif
