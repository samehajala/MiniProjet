#ifndef PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
#define PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
#include <vector>
#include<set>
#include <fstream>
#include "PrixJournalier.h"
using namespace std;
template <typename Container>
class PersistancePrixJournaliers
{
public:
    static Container<PrixJournalier> lirePrixJournaliersDUnFichier(string chemin)
    {
        Container historique;
        ifstream f(chemin);
        int nbLignes = 0;
        string entete;
        if (f.is_open())
        {
            f >> entete;
            while (!f.eof())
            {
                PrixJournalier pj;
                f >> (pj);
                if( constexpr (is_same_v<Container, set<PrixJournalier>>))
                {
                    historique.insert(pj); // Use insert for sets
                }
                else
                {
                    historique.push_back(pj); // Use push_back for vectors
                }
                nbLignes++;
            }
        }
        return historique;
    }
};

#endif // PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
