#include <iostream>
#include "Date.h"
#include "PrixJournalier.h"
#include <string>

#include <set>
using namespace std;

Date PrixJournalier::getDate() const
{
    return date;
}
float PrixJournalier::getPrix() const
{
    return prix;
}
string PrixJournalier::getNomAction() const
{
    return nomAction;
}

bool PrixJournalier::operator<(const PrixJournalier &other) const
{
    return date < other.date;
}

bool PrixJournalier::operator<=(const PrixJournalier &other) const
{
    return date <= other.date;
}

bool PrixJournalier::operator>(const PrixJournalier &other) const
{
    return date > other.date;
}

bool PrixJournalier::operator>=(const PrixJournalier &other) const
{
    return date >= other.date;
}

PrixJournalier::PrixJournalier(Date date, string nomAction, float prix)
{
    this->date = date;
    this->nomAction = nomAction;
    this->prix = prix;
}

ostream &operator<<(ostream &output, const PrixJournalier &prixJ)
{
    output << prixJ.date << ":"
           << "Nom de l'action: " << prixJ.nomAction << " Prix: " << prixJ.prix << endl;
    return output;
}
istream &operator>>(istream &input, PrixJournalier &prixj)
{
    // Test avec input user : pas de lecture du fichier CSV
    input >> prixj.date;
    char tab[100];
    input.getline(tab, 100, ';');
    prixj.nomAction = tab;
    input.getline(tab, 100, '\n');
    prixj.prix = atof(tab);
    return input;
}
