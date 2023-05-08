#include<iostream>
#include<string>
#include<vector>
#include"BourseVector.h"
#include<fstream>

vector<string> BourseVector::getActionsDisponibleParDate(const Date& dateEntree) const {
    vector<string> actions;
    if(dateEntree>dateDuJour)
    {
        return actions ;
    }
    for(auto pj=Historique.begin();pj!= Historique.end();++pj)
    {
        if(pj->getDate()<=dateEntree && pj->getDate()<dateDuJour)
        {
            if (pj->getDate()==dateEntree){
            actions.push_back(pj->getNomAction()) ;
            }
        }
    }
    return actions;
}

vector<PrixJournalier> BourseVector::getPrixJournalierParDate(const Date& dateEntree) const  {
    vector<PrixJournalier> prixJournaliers;
    if(dateEntree>dateDuJour)
    {
        return prixJournaliers ;
    }
    for (auto pj=Historique.begin();pj!=Historique.end();++pj) {
        if (pj->getDate()<= dateEntree) {
            if (pj->getDate()==dateEntree){
            prixJournaliers.push_back(*pj);
            }
        }
    }
    return prixJournaliers;
}
float BourseVector::getPrixJournalierParDatePourUneAction(const Date& dateEntree ,const string& nomAction  ) const
{
    float PrixU=0.0;
    
    vector<PrixJournalier> prixJournaliers = getPrixJournalierParDate(dateEntree);
    

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


void BourseVector::PasserALaJourneeSuivante()
{
    dateDuJour.passToNextDay() ;
}
