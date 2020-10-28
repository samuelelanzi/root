#include "invMass.hpp"

double invMass(Particle p1, Particle p2) {
	double E1 = p1.Energy();
    double E2 = p2.Energy();

    P P1 = p1.getP();
    P P2 = p2.getP();

    double sumE = std::pow(E1 + E2, 2);

    double sumPx = P1.fPx + P2.fPx;
    double sumPy = P1.fPy + P2.fPy;
    double sumPz = P1.fPz + P2.fPz;

    double modP = std::sqrt(sumPx * sumPx + sumPy * sumPy + sumPz * sumPz);

    return std::sqrt(sumE * sumE - modP * modP);
}
