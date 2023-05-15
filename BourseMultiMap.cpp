#include"BourseMultiMap.h"

vector<string> BourseMultiMap::getActionsDisponibleParDate(const Date& dateEntree) const {
    vector<string> actions;
    if(dateEntree > dateDuJour) {
        return actions;
    }
    auto range = Historique.equal_range(dateEntree);
    for (auto it = range.first; it != range.second; ++it) {
        if ((it->second).getDate() <= dateDuJour) {
            actions.push_back((it->second).getNomAction());
        }
    }
    return actions;
}
vector<PrixJournalier> BourseMultiMap::getPrixJournalierParDate(const Date& dateEntree) const {
    vector<PrixJournalier> prixJournaliers;
    if(dateEntree>dateDuJour) {
        return prixJournaliers;
    }
    auto range = Historique.equal_range(dateEntree);
    for (auto it = range.first; it != range.second; ++it) {
        prixJournaliers.push_back(it->second);
    }
    return prixJournaliers;
}
float BourseMultiMap::getPrixJournalierParDatePourUneAction(const Date& dateEntree, const string& nomAction) const {
    float prix = 0.0;
    if (dateEntree > dateDuJour) {
        return prix;
    }
    auto range = Historique.equal_range(dateEntree);
    for (auto it = range.first; it != range.second; ++it) {
        if ((it->second).getNomAction() == nomAction) {
            prix = (it->second).getPrix();
            break;
        }
    }
    return prix;
}
float BourseMultiMap::getDernierPrixDuneAction(const Date& dateFinSimulation, const string& nomAction) const
{
    auto lower = Historique.lower_bound(dateFinSimulation);
    if (lower == Historique.end() || lower->first > dateFinSimulation || dateDuJour < dateFinSimulation)
    {

        return -1.0f;
    }

    float dernierPrix = -1.0f;
    auto upper = Historique.upper_bound(dateFinSimulation);
    for (auto it = lower; it != upper; ++it)
    {
        if (it->second.getNomAction() == nomAction)
        {
            dernierPrix = it->second.getPrix();
        }
    }

    return dernierPrix;
}
