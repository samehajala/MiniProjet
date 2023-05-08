#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include<string>
using namespace std ;
enum typeTransaction {Acheter,Vendre,Rien};
class Transaction
{
    typeTransaction type ;
    string nomAction ;
    int quantite ;
public :
    Transaction(){}
    Transaction(typeTransaction tx):type(tx) {}
    Transaction(typeTransaction tx ,string action,int qte):type(tx),nomAction(action),quantite(qte){}
    string  getNomAction() const ;
    int getQuantite() const ;
    typeTransaction getTypeTransaction()const{return type ; }
};
#endif // TRANSACTION_H_INCLUDED
