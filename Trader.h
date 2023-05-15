#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"Bourse.h"
#include"PorteFeuille.h"
#include"Transaction.h"
class Trader
{
public :
    virtual Transaction choisirTransaction(const Bourse& bourse, const PorteFeuille& porteFeuille)=0 ;
    virtual ~Trader() {} ;
};

#endif // TRADER_H_INCLUDED
