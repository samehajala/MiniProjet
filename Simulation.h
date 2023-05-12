#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "TraderAleatoire.h"
#include <map>
template <typename BourseType>
class Simulation
{
private:

    BourseType bourse;

public:
    static map<string, long> executer(BourseType &bourse, Trader &trader, Date dateDebut, Date dateFin, double solde);
};

#endif // SIMULATION_H_INCLUDED
