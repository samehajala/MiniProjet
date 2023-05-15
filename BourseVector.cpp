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
        if(pj->getDate()==dateEntree && (pj->getDate()<dateDuJour || pj->getDate()==dateDuJour) ){
            actions.push_back(pj->getNomAction()) ;

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
        if (pj->getDate() == dateEntree) {
            prixJournaliers.push_back(*pj);
        }
    }
    return prixJournaliers;
}
float BourseVector::getPrixJournalierParDatePourUneAction(const Date& dateEntree ,const string& nomAction  ) const
{
    float PrixU=0.0;
    vector<PrixJournalier> prixJournaliers;
    for (auto pj=Historique.begin();pj!=Historique.end();++pj)
    {
        if (pj->getDate() == dateEntree)
        {
            prixJournaliers.push_back(*pj);
        }
    }
    if(dateEntree>dateDuJour)
    {
        return PrixU ;
    }
    for(auto pj=Historique.begin();pj!=Historique.end();++pj)
    {
        if(pj->getDate()==dateEntree && pj->getNomAction()==nomAction)
        {
            PrixU=pj->getPrix() ;
        }
    }
    return PrixU ;
}

float BourseVector::getDernierPrixDuneAction(const Date& dateFinSimulation, const string& nomAction) const
{
    if (dateFinSimulation < Historique.begin()->getDate() || dateFinSimulation > Historique.rbegin()->getDate() || dateDuJour < dateFinSimulation)
    {

        return -1.0f;
    }

    float dernierPrix = -1.0f;
    Date dateLimite = dateFinSimulation;
    dateLimite.passToNextDay();
    PrixJournalier p(dateFinSimulation, nomAction);

    for (auto it = Historique.begin(); it != Historique.end(); ++it)
    {
        if (dateLimite<=it->getDate() )
        {
            break;
        }

        if (it->getNomAction() == nomAction)
        {
            dernierPrix = it->getPrix();
        }
    }

    return dernierPrix;
}


/*float BourseVector::getDernierPrixDuneAction(const Date& dateFinSimulation ,const  string& nomAction) const
{
  if (dateFinSimulation<Historique.begin()->getDate()||Historique.rbegin()->getDate()<dateFinSimulation || (dateDuJour<dateFinSimulation))//if the searched date is lower/greater than the upper bound of the set or wants to see into the future return empty vector (out of search range)
            return -1;
    float dernierPrix=-1;
    Date dateLimite(dateFinSimulation);
    dateLimite.passToNextDay();
    PrixJournalier p(dateFinSimulation,nomAction) ;
    for (Date d=Historique.begin()->getDate(); d < dateLimite; ++d)
    {
         auto it=find(Historique.begin(),Historique.end(),p) ;
         if (it!=Historique.end())
        {
            dernierPrix= it->getPrix();
        }
    }
    return dernierPrix;

}*/
