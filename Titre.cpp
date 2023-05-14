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
bool Titre::operator<(const Titre& titre) const
{
    if (nomAction == titre.getNomAction())
        return quantite < titre.getQuantite();
    else
        return nomAction < titre.getNomAction();
}