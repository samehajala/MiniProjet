#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include"PrixJournalier.h"
#include"PersistancePrixJournaliers.h"

#include<string>
#include"Date.h"
class Bourse
{
protected:
    Date dateDuJour ;
public:

    Bourse(){}
    Bourse(Date d){dateDuJour=d ; }
    Date getDateCourante()const { return dateDuJour ; }
    virtual set<string> getActionsDisponibleParDate( const Date& DateEntree ) const =0 ;
    virtual set<PrixJournalier> getPrixJournalierParDate(const  Date& DateEntree ) const =0 ;
    virtual float getPrixJournalierParDatePourUneAction(const Date& DateEntree ,const string& nomAction  )const =0 ;
    virtual void PasserALaJourneeSuivante()=0 ;

};


#endif // BOURSE_H_INCLUDED
