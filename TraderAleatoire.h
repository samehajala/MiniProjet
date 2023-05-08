#ifndef TRADERALEATOIRE_H_INCLUDED
#define TRADERALEATOIRE_H_INCLUDED
#include"Trader.h"
class TraderAleatoire : public Trader
{
public :
    Transaction choisirTransaction(const Bourse& bourse , const PorteFeuille& porteFeuille )override ;
};

#endif // TRADERALEATOIRE_H_INCLUDED
