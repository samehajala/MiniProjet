#ifndef TRADERALGORITHMIQUE_H_INCLUDED
#define TRADERALGORITHMIQUE_H_INCLUDED

#include"Trader.h"
class TraderAlgorithmique : public Trader
{
    int nombreTotalDesTransactions ;
public :
    TraderAlgorithmique(){nombreTotalDesTransactions=2;}
    Transaction choisirTransaction(const Bourse& bourse , const PorteFeuille& porteFeuille )override ;
};

#endif // TRADERALGORITHMIQUE_H_INCLUDED
