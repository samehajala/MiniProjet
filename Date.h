#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
using namespace std ;
class Date
{
private:
    int dd , mm , yyyy ;
public:
    Date(){}
    Date(int d , int m , int y)
    {
        yyyy=y ;
        mm=m  ;
        dd=d ;
    }
    int  getDay()  const ;
    int  getMonth()  const ;
    int  getYear()  const;
    bool  isLeapYear()  const ;
    int dayInMonth() const ;
    void setDate(int d,int m,int y)
    {
        dd=d ;
        mm=m ;
        yyyy=y ;
    }
    void passToNextDay() ;
    bool operator==(const Date& otherDay) const  ;
    bool operator!=(const Date& otherDay)  const ;
    Date operator++() ;
    bool operator<(const Date& otherDay) const ;
    bool operator<=(const Date& otherDay) const  ;
    bool operator>(const Date& otherDay) const ;
    friend ostream& operator<<(ostream& output, const Date& date) ;
    friend istream& operator>>(istream& input,Date& date ) ;
    friend istream& lire_date_stdin(istream& input, Date& date) ;
};


#endif // DATE_H_INCLUDED
