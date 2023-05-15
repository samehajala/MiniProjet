#include"TraderAlgorithmique.h"
#include<vector>
#include <cstdlib>
#include <ctime>
#include<string>
Transaction TraderAlgorithmique::choisirTransaction(const Bourse& bourse, const PorteFeuille& porteFeuille)
{

nombreTotalDesTransactions++ ;
cout<<nombreTotalDesTransactions<<endl;
   vector<PrixJournalier>  actions=bourse.getPrixJournalierParDate(bourse.getDateCourante()) ;
   int choix=nombreTotalDesTransactions % 3 ;// faire le choix d'acheter ou vendre ou rien faire
   vector<Titre> titresPossedes=porteFeuille.getTitres() ;
   if(titresPossedes.size()==0&& choix==1)
   {
       choix=2 ;
   }
     if(actions.size()==0&& choix==0)
   {
       choix=2 ;
   }

   if(choix==0) //le choix ici c'est acheter ;
    {
        int randquantite= (rand()%10)+1 ;
        int indexActionAAcheter=rand()%actions.size() ;
        string  nomactionAAcheter=actions[indexActionAAcheter].getNomAction() ;

        return Transaction(Acheter,nomactionAAcheter,randquantite);
    }
    else if(choix==1)//le choix ici c'est vendre
    {
        int indexActionAVendre=rand()%titresPossedes.size() ;
        int randquantite=rand()%titresPossedes[indexActionAVendre].getQuantite() ;
        randquantite+=1 ;
        string  nomactionAVendre=titresPossedes[indexActionAVendre].getNomAction() ;

        return Transaction(Vendre,nomactionAVendre,randquantite) ;
    }
    else
    {

        return Transaction(Rien) ;
    }
}
