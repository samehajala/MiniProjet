#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include"Date.h"
#include"string"
#include<vector>
class PrixJournalier
{
private:
    Date date ;
    string nomAction ;
    float prix ;

public:
    PrixJournalier(){}
    PrixJournalier(Date journee):date(journee) {}
    PrixJournalier(Date,string,float);
    PrixJournalier(Date d,string nom):date(d),nomAction(nom) {}
    Date getDate() const  ;
    float getPrix() const  ;
    string  getNomAction() const  ;
    bool operator<(const PrixJournalier& prixj)const  ;
    friend ostream& operator<<(ostream& output, const PrixJournalier& prixj) ;
    friend istream& operator>>(istream& input,PrixJournalier& prixj ) ;
};
#endif // PRIXJOURNALIER_H_INCLUDED
