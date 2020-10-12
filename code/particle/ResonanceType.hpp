#ifndef RESONANCETYPE_HPP
#define RESONANCETYPE_HPP

#include "ParticleType.hpp"

class ResonanceType : public ParticleType {
protected:
    double width_;
public:
    ResonanceType(ParticleType const& particle, double width);

    double getWidth();

    void print() override;
};

#endif
