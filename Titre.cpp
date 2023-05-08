#include"Titre.h"
string Titre::getNomAction() const
{
    return nomAction ;
}
int Titre::getQuantite() const
{
    return quantite ;
}

bool Titre::operator==(const Titre& titre) const
{
    return nomAction==titre.getNomAction() && quantite==titre.getQuantite() ;
}
