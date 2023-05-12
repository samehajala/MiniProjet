#ifndef BOURSEVECTOR_H_INCLUDED
#define BOURSEVECTOR_H_INCLUDED
#include <vector>
#include <string>
#include"Bourse.h"
class BourseVector : public Bourse {
private:
    vector<PrixJournalier> Historique;

public:
    BourseVector();
    BourseVector(const Date&d,vector<PrixJournalier> histo ): Bourse(d) , Historique(histo) {}
    vector<string> getActionsDisponibleParDate(const Date& dateEntree) const ;
    vector<PrixJournalier> getPrixJournalierParDate(const Date& dateEntree) const ;
    float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  ) const override ;
    void PasserALaJourneeSuivante() override ;
};

#endif // BOURSEVECTOR_H_INCLUDED
