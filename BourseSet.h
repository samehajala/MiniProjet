#ifndef BOURSESET_H_INCLUDED
#define BOURSESET_H_INCLUDED

#include <set>
#include<vector>
#include <string>
#include"Bourse.h"
class BourseSet : public Bourse {
private:
    set<PrixJournalier> Historique;

public:
    BourseSet();
    BourseSet(const Date&d,set<PrixJournalier> histo ): Bourse(d) , Historique(histo) {}
    vector<string> getActionsDisponibleParDate(const Date& dateEntree) const override;
    vector<PrixJournalier> getPrixJournalierParDate(const Date& dateEntree) const override;
    float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  ) const override ;
    float getDernierPrixDuneAction(const Date& date,const string& action)const override ;

};

#endif // BOURSESET_H_INCLUDED
