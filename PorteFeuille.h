#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include"Titre.h"
#include<vector>
class PorteFeuille
{
    double solde ;
    vector<Titre> Titres ;
public :
    PorteFeuille(double sld=1000):solde(sld){} ;
    double getSolde() const {return solde ; }
    vector<Titre> getTitres() const {return Titres ; }
    void acheterTitre(Titre titre , double montant  ) ;
    void vendreTitre(Titre titre , double montant ) ;
};


#endif // PORTEFEUILLE_H_INCLUDED
