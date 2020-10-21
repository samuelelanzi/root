#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP

#include "ParticleType.hpp"

class ResonanceType : public ParticleType {
private:
    double const fWidth;
public:
    ResonanceType(ParticleType particle_t, double width);
    double getWidth();
    void Print() override;
};

#endif
