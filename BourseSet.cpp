#include"BourseSet.h"
#include <bits/stdc++.h>
vector<string> BourseSet::getActionsDisponibleParDate(const Date& dateEntree) const {

    vector<string> actions;

    if(dateEntree > dateDuJour) {
        return actions;
    }

    PrixJournalier recherchePrix(dateEntree) ;

    auto it = Historique.lower_bound(recherchePrix);
    while (it != Historique.end() && it->getDate() == dateEntree && it->getDate() <= dateDuJour) {
        actions.push_back(it->getNomAction());
        ++it;
    }

    return actions;
}
/*
vector<string> BourseSet::getActionsDisponibleParDate(const Date& dateEntree) const {
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
}*/

vector<PrixJournalier> BourseSet::getPrixJournalierParDate(const Date& dateEntree) const  {
    vector<PrixJournalier> prixJournaliers;
   if(dateEntree > dateDuJour) {
        return prixJournaliers ;
    }

    PrixJournalier recherchePrix(dateEntree) ;

    auto it = Historique.lower_bound(recherchePrix);
    while (it != Historique.end() && it->getDate() == dateEntree && it->getDate() <= dateDuJour) {
        prixJournaliers.push_back(*it);
        ++it;
    }
    return prixJournaliers;
}
/*
vector<PrixJournalier> BourseSet::getPrixJournalierParDate(const Date& dateEntree) const  {
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
}*/

float BourseSet::getPrixJournalierParDatePourUneAction(const Date& dateEntree, const string& nomAction) const {
    float prixU = 0.0;
    if (dateEntree > dateDuJour) {
        return prixU;
    }
    auto range = Historique.equal_range(PrixJournalier(dateEntree,nomAction));
    for (auto it = range.first; it != range.second; ++it) {
        if (it->getNomAction() == nomAction && it->getDate() == dateEntree) {
            prixU = it->getPrix();
            break;
        }
    }
    return prixU;
}
/*
float BourseSet::getPrixJournalierParDatePourUneAction(const Date& dateEntree ,const string& nomAction  ) const
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
}*/
float BourseSet::getDernierPrixDuneAction(const Date& dateFinSimulation, const string& nomAction) const
{
    if (dateFinSimulation < Historique.begin()->getDate() || dateFinSimulation > Historique.rbegin()->getDate() || dateDuJour < dateFinSimulation)
    {

        return -1.0f;
    }

    float dernierPrix = -1.0f;
    Date dateLimite = dateFinSimulation;
    dateLimite.passToNextDay();
    PrixJournalier p(dateFinSimulation, nomAction);

    auto it = Historique.lower_bound(p);

    if (it == Historique.end())
    {

        return -1.0f;
    }

    while (it != Historique.end() && it->getDate() < dateLimite)
    {
        if (it->getNomAction() == nomAction)
        {
            dernierPrix = it->getPrix();
        }
        ++it;
    }

    return dernierPrix;
}
