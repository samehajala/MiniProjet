#include"PorteFeuille.h"
using namespace std ;
void PorteFeuille::acheterTitre(Titre titre , double montant )
{
    if(solde>montant)
    {
        solde=solde-montant ;
        for(auto t:Titres)
        {
            if(t==titre)
            {
                t.setQuantite(titre.getQuantite()+t.getQuantite()) ;
                return ;
            }
        }
        Titres.push_back(titre) ;
    }

}
void PorteFeuille::vendreTitre(Titre titre,double montant )
{
    for (int i=0;i<Titres.size();i++)
    {
        if (Titres[i]==titre)
        {
            if(Titres[i].getQuantite()==titre.getQuantite())

            {
                Titres.erase(Titres.begin()+i) ;
            }
            else
            {
                Titres[i].setQuantite(Titres[i].getQuantite()-titre.getQuantite()) ;
            }
            solde=solde+montant ;

        }
    }
}
