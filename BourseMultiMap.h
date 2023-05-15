#ifndef BOURSEMULTIMAP_H_INCLUDED
#define BOURSEMULTIMAP_H_INCLUDED
#include"Bourse.h"
#include<map>
class BourseMultiMap : public Bourse
{
    private:
    multimap<Date,PrixJournalier> Historique;
public:
    BourseMultiMap();
    BourseMultiMap(const Date&d,multimap<Date,PrixJournalier> histo ): Bourse(d) , Historique(histo) {}

    vector<string> getActionsDisponibleParDate(const Date& dateEntree) const override;
    vector<PrixJournalier> getPrixJournalierParDate(const Date& dateEntree) const override;
    float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  ) const override ;
    float getDernierPrixDuneAction(const Date& date,const string& action)const override ;

};


#endif // BOURSEMULTIMAP_H_INCLUDED
