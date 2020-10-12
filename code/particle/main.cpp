#include <iostream>

class ParticleType {
private:
    std::string name_;
    double mass_;
    int charge_;

public:
    ParticleType(std::string name, double mass, int charge) : name_{name}, mass_{mass}, charge_{charge} { } 

    std::string getName() const { return name_; }
    double getMass() const { return mass_; }
    int getCharge() const { return charge_; }

    void print() {
        std::cout << "name: " << name_ << '\n';
        std::cout << "mass: " << mass_ << '\n';
        std::cout << "charge: " << charge_ << '\n';
    }
};

int main() { 
    ParticleType particle {"electron", 9.109e-31, -1};
    particle.print();
}
