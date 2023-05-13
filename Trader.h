#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"Bourse.h"
#include"PorteFeuille.h"
#include"Transaction.h"

template <typename BourseType>
class Trader
{
public :
    virtual Transaction choisirTransaction(const BourseType& bourse, const PorteFeuille& porteFeuille)=0 ;
    virtual ~Trader() {} ;
};

#endif // TRADER_H_INCLUDED
