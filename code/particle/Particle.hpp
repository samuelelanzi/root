#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "ParticleType.hpp"
#include "ResonanceType.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

struct P {
  double fPx = 0;
  double fPy = 0;
  double fPz = 0;
};

class Particle {
private:
  std::vector<ParticleType*> fParticleType{};
  std::string fName;
  P fP;
  int fNParticleType = fParticleType.size();
  int fIParticle;
  ParticleType* FindParticle(std::vector<ParticleType*> &particle_v);
  void Boost(double bx, double by, double bz);

public:
  Particle(ParticleType* particleT, std::string name, P p);

  int getIParticle();

  P getP();

  void setP(double const &px, double const &py, double const &pz);

  double getParticleMass();

  void printParticle();

  //ParticleType *AddParticleType(std::string const &name, double const &mass,
  //                              int const &charge, int const &width);

  double Energy();

  void Decay2body(Particle &dau1, Particle &dau2);

  ParticleType* getParticleType();
};

#endif