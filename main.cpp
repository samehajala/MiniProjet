#include <iostream>
#include"Date.h"
#include"PersistancePrixJournaliers.h"
#include"PrixJournalier.h"
#include"BourseVector.h"
#include<map>
#include"Transaction.h"
#include"TraderAleatoire.h"
#include<string>
#include"Titre.h"
#include <ctime>
#include"BourseSet.h"
#include"Simulation.h"
#include"BourseMultiMap.h"
#include"TraderAlgorithmique.h"
#include<chrono>
#include<set>
using namespace std;

int main()
{
    auto tStart = chrono::high_resolution_clock::now();
    srand(time(nullptr));//time(nullptr)
     PersistancePrixJournaliers pers ;
    vector<PrixJournalier> prixJour ;
    prixJour=pers.lirePrixJournaliersDUnFichier("prices.csv") ;
    //cout<<"La taille de votre fichier csv est:\t"<<prixJour.size()<<endl ;
    set<PrixJournalier> prixJourSet;
    for(auto pj=prixJour.begin();pj!=prixJour.end();++pj)
    {
        prixJourSet.insert(*pj) ;
    }
    multimap<Date,PrixJournalier>  prixJourMultiMap ;
    for(auto pj=prixJour.begin();pj!=prixJour.end();++pj )
    {
        prixJourMultiMap.insert(make_pair(pj->getDate(),*pj)) ;
    }


    //cout<<"date debut simulation"<<bourse.getDateCourante()<<endl ;
    bool quiter=false ;
    while(!quiter)
    {
        cout << "\n";
        cout << "==================== MENU ===========================\n";
        cout << "============  Simulation de Trading en Bourse========\n";

        int dd ;
        cout<<"donner le jour de debut de simulation"<<endl ;
        cin>>dd ;
         int md ;
        cout<<"donner le de debut de simulation"<<endl ;
         cin>>md ;
         int yd ;
        cout<<"donner l'annee de debut de simulation"<<endl ;
        cin>> yd ;
        Date d1(dd,md,yd);
        cout<<"La date de debut de simulation est "<<d1<<endl ;
        BourseVector bourse(d1,prixJour) ;
        BourseSet bourseset(d1,prixJourSet) ;
        BourseMultiMap bourseMultiMap(d1,prixJourMultiMap) ;
        int choix ;
        cout<<"\t    Entrer votre choix de Bourse \t\t\t\n "<< endl ;
        cout<<"-1/ Bouse de Type Set "<<endl ;
        cout<<"-2/ Bouse de Type Vector "<<endl ;
        cout<<"-3/ Bouse de Type MultiMap "<<endl ;
        cin>>choix ;
        vector<Titre> titres ;

    PorteFeuille p ;
    TraderAleatoire TA ;
    TraderAlgorithmique TrAlgo ;
    Transaction tx ;
    int df ;
        cout<<"donner le jour de fin de simulation"<<endl ;
        cin>>df;
         int mf ;

        cout<<"donner le de fin de simulation"<<endl ;
        cin>>mf;
         int yf ;
        cout<<"donner l'annee de fin de simulation"<<endl ;
        cin>>yf;
        Date d3(df,mf,yf);
    cout<<"Date fin simulation"<<d3<<endl ;
    int choixTrader ;
    cout << "============  Le trader est Aleatoire : Taper 1 ===============\n";
    cout << "============  Le trader est Algorithmique : Taper 0 ===============\n";
    cin>>choixTrader ;
    map<string,long> statistiquesSimulation ;


    if(choix==1)
     {
        if(choixTrader==0)
        {
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }
        else if (choixTrader==1){
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }

     }
    else if (choix==2)
    {
       if(choixTrader==0)
        {
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }
        else if (choixTrader==1){
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }
    }
    else if (choix==3)
    {
        if(choixTrader==0)
        {
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }
        else if (choixTrader==1){
            statistiquesSimulation=Simulation::executer(bourseset,TrAlgo,d1,d3,1000) ;
        cout<<"on a fini la Simulation avec succes et voici les statistiques "<<endl ;
        cout<<"le gain est "<<statistiquesSimulation["solde"]-1000<<endl ;
        cout<<"Le nombre de getaction est \t"<<statistiquesSimulation["nombreGetActionsDisponibleParDate"]<<endl ;
        cout<<"Le nombre total des transactions est:\t"<<statistiquesSimulation["nombre Des Transactions Totales"]<<endl ;
        cout<<"le temps des transaction est \t"<<statistiquesSimulation["tempsTransactionParJour"]<<endl  ;
        cout<<"Le nombre des actions acheter est:\t"<<statistiquesSimulation["NombreDesTransactionAcheter"]<<endl ;
        cout<<"Le nombre des actions qui ont echouees est:\t"<<statistiquesSimulation["NombreDesTransactionEchouees"]<<endl ;
        cout<<"Le nombre des actions Vendre est:\t"<<statistiquesSimulation["NombreDesTransactionVendre"]<<endl ;
        cout<<"Le solde final est:\t"<<statistiquesSimulation["solde"]<<endl ;
        cout<<"Le temps de getAction est \t"<<statistiquesSimulation["tempsGetActionsDisponibleParDate"]<<endl ;
        cout<<"La moyenne de getAction est \t"<<statistiquesSimulation["moyenneGetActionParDate"]<<endl ;
        cout<<"Le nombre GetPrixParAction\t"<<statistiquesSimulation["nombreGetPrixParAction"]<<endl ;
        cout<<"Le temps GetPrixParAction\t"<<statistiquesSimulation["tempsGetPrixParAction"]<<endl ;
        }
    }
    else
    {
        quiter=true ;

    }
    auto tEnd = chrono::high_resolution_clock::now();
    double temps_ecoule = chrono::duration<double, milli>(tEnd - tStart).count();
    cout << "La mesure du temps d'execution est de " << temps_ecoule << "milli secondes . " << endl;
    }

    return 0;
}
