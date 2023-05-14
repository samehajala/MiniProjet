#ifndef PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
#define PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
#include<vector>
#include<fstream>
#include"PrixJournalier.h"
#include<set>
using namespace std;

class PersistancePrixJournaliers
{
    public:
        static set<PrixJournalier> lirePrixJournaliersDUnFichier(string chemin){
            set<PrixJournalier> historique;
            ifstream f(chemin);
            int nbLignes= 0;
            string entete;
            if(f.is_open()){
                f>>entete;
                while(!f.eof()){
                    PrixJournalier pj;
                    f>>(pj);
                    historique.insert(pj);
                    nbLignes++;
                }
            }
            return historique;
        }
};



#endif // PERSISTANCEPRIXJOURNALIERS_H_INCLUDED
