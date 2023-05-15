#include"Titre.h"
string Titre::getNomAction() const
{
    return nomAction ;
}
int Titre::getQuantite() const
{
    return quantite ;
}
void Titre::setQuantite(int qt)
{
    if(qt>0)
     {quantite=qt ;}
}
bool Titre::operator==(const Titre& titre) const
{
    return nomAction==titre.getNomAction()  ;
}
