#include"PorteFeuille.h"
using namespace std ;
#include"PorteFeuille.h"
using namespace std ;
void PorteFeuille::acheterTitre(Titre titre , double montant )
{
    if(solde>montant)
    {
        solde=solde-montant ;
        Titres.push_back(titre) ;
    }

}
void PorteFeuille::vendreTitre(Titre titre,double montant )
{
    for (int i=0;i<Titres.size();i++)
    {
        if (Titres[i]==titre)
        {
            Titres.erase(Titres.begin()+i) ;
            solde=solde+montant ;
        }
    }
    
}
     
