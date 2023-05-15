#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include"TraderAleatoire.h"
#include<map>
class Simulation
{
public :
    static map<string,long> executer(Bourse& bourse , Trader& trader , Date dateDebut, Date dateFin,double solde ) ;
};

#endif // SIMULATION_H_INCLUDED
