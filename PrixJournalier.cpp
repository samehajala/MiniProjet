#include<iostream>
#include"Date.h"
#include"prixJournalier.h"
#include<string>
#include<vector>
using namespace std ;

Date PrixJournalier::getDate() const {
    return date;

}
float PrixJournalier::getPrix() const {
    return prix;

}
string PrixJournalier:: getNomAction() const {
    return nomAction;

}


PrixJournalier::PrixJournalier(Date date,string nomAction,float prix)
{
    this->date=date ;
    this->nomAction=nomAction;
    this->prix=prix ;
}
bool PrixJournalier::operator<(const PrixJournalier& prixJ) const
{
    if (this->date==prixJ.getDate())
    {
        return this->getNomAction()<prixJ.getNomAction() ;
    }
    return (this->date<prixJ.getDate() ) ;
}
ostream& operator<<(ostream& output, const PrixJournalier& prixJ)
{
    output<<prixJ.date<<":"<<"Nom de l'action: "<<prixJ.nomAction<<" Prix: "<<prixJ.prix<<endl ;
    return output ;
}
istream& operator>>(istream& input,PrixJournalier& prixj)
{
// Test avec input user : pas de lecture du fichier CSV
    input>>prixj.date ;
    char tab[100] ;
    input.getline(tab,100,';') ;
    prixj.nomAction=tab ;
    input.getline(tab,100,'\n') ;
    prixj.prix=atof(tab) ;
    return input ;
}

