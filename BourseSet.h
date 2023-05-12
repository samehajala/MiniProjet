#ifndef BOURSESET_H_INCLUDED
#define BOURSESET_H_INCLUDED
#include <set>
#include <string>
#include"Bourse.h"
class BourseSet : public Bourse {

private:
    set<PrixJournalier> Historique;

public:
    BourseSet();
    BourseSet(const Date&d,set<PrixJournalier> histo ): Bourse(d) , Historique(histo) {}
    set<string> getActionsDisponibleParDate(const Date& dateEntree) const ;
    set<PrixJournalier> getPrixJournalierParDate(const Date& dateEntree) const ;
    float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  ) const override ;
    void PasserALaJourneeSuivante() override ;
};




#endif // BOURSESET_H_INCLUDED
