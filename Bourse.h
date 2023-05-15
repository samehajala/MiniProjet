#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include"PrixJournalier.h"
#include"PersistancePrixJournaliers.h"
#include<vector>
#include<string>
#include"Date.h"
class Bourse
{
protected:
    Date dateDuJour ;
public:
    Bourse(){}
    Bourse(Date d){dateDuJour=d ; }
    virtual ~Bourse(){}
    Date getDateCourante()const { return dateDuJour ; }
    virtual vector<string> getActionsDisponibleParDate( const Date& DateEntree ) const =0 ;
    virtual vector<PrixJournalier> getPrixJournalierParDate(const  Date& DateEntree ) const =0 ;
    virtual float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  )const =0 ;
    virtual float getDernierPrixDuneAction(const Date& date,const string& action)const =0 ;
    void PasserALaJourneeSuivante()
    {
        dateDuJour.passToNextDay() ;
    }

};


#endif // BOURSE_H_INCLUDED

