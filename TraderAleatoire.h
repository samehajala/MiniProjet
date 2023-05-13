#ifndef TRADERALEATOIRE_H_INCLUDED
#define TRADERALEATOIRE_H_INCLUDED
#include"Trader.h"
template <typename BourseType>
class TraderAleatoire : public Trader<BourseType> 
{
  
public :
    Transaction choisirTransaction(const BourseType& bourse , const PorteFeuille& porteFeuille )override ;
};

#endif // TRADERALEATOIRE_H_INCLUDED
