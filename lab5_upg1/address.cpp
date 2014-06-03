#include "address.h"
#include <iostream>
using namespace std;

// Standardkonstruktor
Address::Address()
{
    street = "";
    postalno = "";
    city = "";
}

// Överlagrad konstruktor
Address::Address(string s, string p, string c)
{
    street = s;
    postalno = p;
    city = c;
}

// Setters
void Address::setStreet(string s)
{
    street = s;
}

void Address::setPostalNo(string p)
{
    postalno = p;
}

void Address::setCity(string c)
{
    city = c;
}

// Överlagring av < operatorn
bool Address::operator<(const Address &a) const
{
    bool eq = false;

    if(city == a.getCity())
    {
        eq = (street) < (a.getStreet());
    }
    else
    {
        eq = (city) < (a.getCity());
    }

    return eq;
}

// Överlagring av == operatorn
bool Address::operator==(const Address &a) const
{
    return city == a.getCity();
}

// Avgränsare i fil
const char DELIM='|';

//Överlagring av << utskriftsoperatorn
ostream &operator<<(ostream &os, const Address &a)
{
    os << a.getStreet() << DELIM << a.getPostalNo() << DELIM << a.getCity() << DELIM;

    return os;
}

// Överlagring av >> inläsningsoperatorn
istream &operator>>(istream &is, Address &a)
{
    string s;

    getline(is, s, DELIM);
    a.setStreet(s);

    getline(is, s, DELIM);
    a.setPostalNo(s);

    getline(is, s, DELIM);
    a.setCity(s);

    return is;
}
