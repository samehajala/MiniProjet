#ifndef TITRE_H_INCLUDED
#define TITRE_H_INCLUDED
#include<string>
using namespace std ;
class Titre
{
    string nomAction ;
    int quantite ;
public :
    Titre() ;
    Titre(string nomaction , int qte):nomAction(nomaction) , quantite(qte) {}
    string getNomAction() const ;
    int getQuantite() const  ;
    bool operator==(const Titre& titre) const  ;
    bool operator<(const Titre& titre) const;
};

#endif // TITRE_H_INCLUDED
