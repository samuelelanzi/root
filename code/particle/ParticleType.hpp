#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP

#include <iostream>

class ParticleType {
protected:
    std::string name_;
    double mass_;
    int charge_;

public:
    ParticleType(std::string name, double mass, int charge);

    std::string getName();
    double getMass();
    int getCharge();

    virtual void print();
};

#endif