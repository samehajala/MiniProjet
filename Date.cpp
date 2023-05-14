#include <iostream>
#include <string>
#include "Date.h"
#include <fstream>
#include <sstream>
int Date::getDay() const
{
    return dd;
}
int Date::getMonth() const
{
    return mm;
}
int Date::getYear() const
{
    return yyyy;
}
bool Date::isLeapYear() const
{
    return (yyyy % 4 == 0 && yyyy % 100 != 0) || (yyyy % 400 == 0);
}
int Date::dayInMonth() const
{
    switch (mm)
    {
    case 2:
        return isLeapYear() ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}
void Date::passToNextDay()
{
    if (dd < dayInMonth())
    {
        dd++;
    }
    else
    {
        dd = 1;
        if (mm < 12)
        {
            mm++;
        }
        else
        {
            mm = 1;
            yyyy++;
        }
    }
}
Date Date::operator++()
{
    if (dd < dayInMonth())
    {
        dd++;
    }
    else
    {
        dd = 1;
        if (mm < 12)
        {
            mm++;
        }
        else
        {
            mm = 1;
            yyyy++;
        }
    }
    return *this;
}
bool Date::operator==(const Date &otherDay) const
{
    return dd == otherDay.dd && mm == otherDay.mm && yyyy == otherDay.yyyy;
}
bool Date::operator!=(const Date &otherDay) const
{
    if (yyyy != otherDay.dd || mm != otherDay.mm || yyyy != otherDay.yyyy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Date::operator<(const Date &otherDay) const
{
    if (yyyy < otherDay.yyyy)
    {
        return true;
    }
    else if (yyyy > otherDay.yyyy)
    {
        return false;
    }
    else
    {
        if (mm < otherDay.mm)
        {
            return true;
        }
        else if (mm > otherDay.mm)
        {
            return false;
        }
        else
        {
            return dd < otherDay.dd;
        }
    }
}
bool Date::operator<=(const Date &otherDay) const
{
    return *this < otherDay || *this == otherDay;
}
bool Date::operator>=(const Date &otherDay) const
{
    return *this > otherDay || *this == otherDay;
}
bool Date::operator>(const Date &otherDay) const
{
    if (yyyy > otherDay.yyyy)
    {
        return true;
    }
    else if (yyyy < otherDay.yyyy)
    {
        return false;
    }
    else
    {
        if (mm > otherDay.mm)
        {
            return true;
        }
        else if (mm < otherDay.mm)
        {
            return false;
        }
        else
        {
            return dd > otherDay.dd;
        }
    }
}

ostream &operator<<(ostream &output, const Date &date)
{
    output << date.dd << "/" << date.mm << "/" << date.yyyy;
    return output;
}
istream &operator>>(istream &flux, Date &date)
{
    char tab[100];
    flux.getline(tab, 100, '/');
    date.dd = atoi(tab);
    flux.getline(tab, 100, '/');
    date.mm = atoi(tab);
    flux.getline(tab, 100, ';');
    date.yyyy = atoi(tab);
    return flux;
}
istream &lire_date_stdin(istream &input, Date &date)
{

    cout << "donner la date ";
    input >> date.dd;
    cout << "donner le mois ";
    input >> date.mm;
    cout << "donner l'ann�e  ";
    input >> date.yyyy;
    return input;
}
