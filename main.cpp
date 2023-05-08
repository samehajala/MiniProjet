#include <iostream>
#include"Date.h"
#include"PersistancePrixJournaliers.h"
#include"PrixJournalier.h"
#include"BourseVector.h"

#include"Transaction.h"
#include"TraderAleatoire.h"
#include<string>
#include"Titre.h"
#include <ctime>
#include"Simulation.h"
#include<chrono>
using namespace std;

int main()
{
    auto tStart = chrono::high_resolution_clock::now();
    srand(time(nullptr));
     PersistancePrixJournaliers pers ;
    vector<PrixJournalier> prixJour ;
    prixJour=pers.lirePrixJournaliersDUnFichier("prices.csv") ;
    cout<<"La taille de votre fichier csv est:\t"<<prixJour.size()<<endl ;


    Date d1(6,1,2010);

     BourseVector bourse(d1,prixJour) ;

    cout<<bourse.getDateCourante()<<endl ;


    Titre t1("stf",500) ;
    cout<<t1.getQuantite()<<endl ;
    cout<<t1.getNomAction()<<endl ;
    vector<Titre> titres ;
    titres.push_back(t1) ;
    PorteFeuille p ;

    TraderAleatoire TA ;
    Transaction tx ;

    Simulation maSimulation ;

    Date d3(26,3,2010) ;
    map<string,long> statistiquesSimulation ;
    statistiquesSimulation=Simulation::executer(bourse,TA,d1,d3,10000) ;
    cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
    cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
    cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
    cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
    cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
    cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;

    auto tEnd = chrono::high_resolution_clock::now();
    double temps_ecoule = chrono::duration<double, milli>(tEnd - tStart).count();
    cout << "La mesure du temps d'execution est de " << temps_ecoule << "milli secondes . " << endl;

    return 0;
}
