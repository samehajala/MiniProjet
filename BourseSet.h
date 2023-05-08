#ifndef BOURSESET_H_INCLUDED
#define BOURSESET_H_INCLUDED
#include <set>
#include <string>
#include"Bourse.h"
class BourseSet : public Bourse {
private:
    vector<PrixJournalier> Historique;

public:
    BourseSet();
    BourseSet(const Date&d,vector<PrixJournalier> histo ): Bourse(d) , Historique(histo) {}
    set<string> getActionsDisponibleParDate(const Date& dateEntree) const override;
    set<PrixJournalier> getPrixJournalierParDate(const Date& dateEntree) const override;
    float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  ) const override ;
    void PasserALaJourneeSuivante() override ;
};




#endif // BOURSESET_H_INCLUDED
