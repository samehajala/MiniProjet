#include"Simulation.h"
using namespace std ;
map<string , long> Simulation::executer(Bourse &bourse ,Trader& trader , Date dateDebut , Date dateFin,double solde )
{
    map<string,long> maSimulation;
    PorteFeuille porteFeuille(solde) ;
    Date datePrecedente ;
    Date dateCourante=dateDebut ;
    int NombreDesTransactionTotale=0 ;
    int NombreDesTransactionAcheter=0 ;
    int NombreDesTransactionVendre=0 ;
    int NombreDesTransactionRien=0 ;
    int NombreDesTransactionEchouees=0 ;
    while(dateCourante<=dateFin)
    {

        cout<<dateCourante<<endl ;
        vector<string> actionsdisponiblesaujourdhui ;
        actionsdisponiblesaujourdhui=bourse.getActionsDisponibleParDate(bourse.getDateCourante()) ;
        if(actionsdisponiblesaujourdhui.size()==0)
        {
             dateCourante.passToNextDay() ;
            bourse.PasserALaJourneeSuivante() ;
        }
        int nombreTransactionParJour=0 ;
        Transaction transaction=trader.choisirTransaction(bourse,porteFeuille) ;
        if(transaction.getTypeTransaction()==Rien)
        {
            //cout<<"Rien faire"<<endl gfgfg ;
            NombreDesTransactionRien++ ;
        }

        while((nombreTransactionParJour<100) && (transaction.getTypeTransaction()!=Rien))
        {
            if(transaction.getTypeTransaction()==Acheter)
            {

                Titre titreAchete(transaction.getNomAction(),transaction.getQuantite()) ;
                if(porteFeuille.getSolde()>=bourse.getPrixJournalierParDatePourUneAction(dateCourante,transaction.getNomAction())*titreAchete.getQuantite())
                {
                    //cout<<"Achater\t"<<transaction.getNomAction()<<"\t"<<transaction.getQuantite()<<endl ;
                    porteFeuille.acheterTitre(titreAchete,bourse.getPrixJournalierParDatePourUneAction(dateCourante,transaction.getNomAction())*titreAchete.getQuantite()) ;
                    NombreDesTransactionAcheter++ ;

                }
                else
                {
                    //cout<<"La Transaction  "<<"Achater\t"<<transaction.getQuantite()<<"\t"<<transaction.getNomAction()<<"\test impossible"<<endl ;
                    NombreDesTransactionEchouees++ ;
                }
            }
            else
            {
                //cout<<"Vendre\t"<<transaction.getNomAction()<<"\t"<<transaction.getQuantite()<<endl ;
                Titre titreVendre(transaction.getNomAction(),transaction.getQuantite()) ;
                porteFeuille.vendreTitre(titreVendre,bourse.getPrixJournalierParDatePourUneAction(dateCourante,transaction.getNomAction())*titreVendre.getQuantite()) ;
                NombreDesTransactionVendre ++ ;



            }
            transaction=trader.choisirTransaction(bourse,porteFeuille) ;
            nombreTransactionParJour++ ;
            NombreDesTransactionTotale++ ;
        }
        dateCourante.passToNextDay() ;
        bourse.PasserALaJourneeSuivante() ;
        maSimulation["nombre Des Transactions Totales"]=NombreDesTransactionTotale ;
        maSimulation["NombreDesTransactionAcheter"]=NombreDesTransactionAcheter ;
        maSimulation["NombreDesTransactionEchouees"]=NombreDesTransactionEchouees;
        maSimulation["NombreDesTransactionVendre"]=NombreDesTransactionVendre ;
        maSimulation["solde"]=porteFeuille.getSolde() ;

    }
return maSimulation ;
}
