#ifndef PARTICLETYPE_HPP
#define PARTICLETYPE_HPP
#include <iostream>

class ParticleType {
protected:
    std::string const fName;
    double const fMass;
    int const fCharge;
    
public:
    ParticleType(std::string name, double mass, int charge);
    std::string getName();
    double getMass();
    int getCharge();

    virtual void Print();
};

#endif