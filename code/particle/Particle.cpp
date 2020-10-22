#include "Particle.hpp"

Particle::Particle(std::vector<ParticleType*> particle_v, std::string name, P p) : fParticleType{particle_v}, fName{name}, fP{p} {
    FindParticle(particle_v);
}