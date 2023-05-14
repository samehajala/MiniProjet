#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include "Date.h"
#include "string"

class PrixJournalier
{
private:
    Date date;
    string nomAction;
    float prix;

public:
    PrixJournalier() {}
    PrixJournalier(Date, string, float);
    Date getDate() const;
    float getPrix() const;
    string getNomAction() const;
    bool operator<(const PrixJournalier &other)const;
    bool operator<=(const PrixJournalier &other)const;
    bool operator>(const PrixJournalier &other) const;
    bool operator>=(const PrixJournalier &other) const;
    friend ostream &operator<<(ostream &output, const PrixJournalier &prixj);
    friend istream &operator>>(istream &input, PrixJournalier &prixj);
}
;
#endif // PRIXJOURNALIER_H_INCLUDED
