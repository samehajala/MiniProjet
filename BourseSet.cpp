#include<iostream>
#include<string>
#include<set>
#include"BourseSet.h"
#include<fstream>

set<string> BourseSet::getActionsDisponibleParDate(const Date& dateEntree) const {
    set<string> actions;
    if(dateEntree>dateDuJour)
    {
        return actions ;
        
    }
    for(auto pj=Historique.begin();pj!= Historique.end();++pj)
    {
        if(pj->getDate()<=dateEntree && pj->getDate()<dateDuJour)
        {
            if (pj->getDate()==dateEntree){
            actions.insert(pj->getNomAction()) ;
            }


        }
    }

    return actions;
}

set<PrixJournalier> BourseSet::getPrixJournalierParDate(const Date& dateEntree) const  {
    set<PrixJournalier> prixJournaliers;
    if(dateEntree>dateDuJour)
    {
        return prixJournaliers ;
    }
    for (auto pj=Historique.begin();pj!=Historique.end();++pj) {
        if (pj->getDate()<= dateEntree) {
            if (pj->getDate()==dateEntree){
            prixJournaliers.insert(*pj);
            }
        }
    }
    return prixJournaliers;
}
float BourseSet::getPrixJournalierParDatePourUneAction(const Date& dateEntree ,const string& nomAction  ) const
{
    float PrixU=0.0;
    
    set<PrixJournalier> prixJournaliers = getPrixJournalierParDate(dateEntree);
    

    //Recherche du nom d'action dans le vecteur prixJournaliers
    for(auto pj=prixJournaliers.begin();pj!=prixJournaliers.end();++pj)
    {
        if(pj->getNomAction()==nomAction)
        {
            PrixU=pj->getPrix() ;
        }
    }
    return PrixU ;
}


void BourseSet::PasserALaJourneeSuivante()
{
    dateDuJour.passToNextDay() ;
}
