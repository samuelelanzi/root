#include "ParticleType.hpp"

ParticleType::ParticleType(std::string name, double mass, int charge) : name_{name}, mass_{mass}, charge_{charge} { } 

std::string ParticleType::getName() { return name_; }
double ParticleType::getMass() { return mass_; }
int ParticleType::getCharge() { return charge_; }

void ParticleType::print() {
    std::cout << "name: " << name_ << '\n';
    std::cout << "mass: " << mass_ << '\n';
    std::cout << "charge: " << charge_ << '\n';
}