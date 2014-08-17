#include <iostream>
#include <sstream>
#include "person.h"
using namespace std;

// Standardkonstruktor
Person::Person()
{
    persNr = "";
    skoNr = 0;
}

// Överlagrad konstruktor
Person::Person(Name n, Address a, std::string p, int s)
{
    name = n;
    address = a;
    persNr = p;
    skoNr = s;
}

// Setters
void Person::setName(Name n)
{
    name = n;
}

void Person::setAddress(Address a)
{
    address = a;
}

void Person::setPersNr(std::string p)
{
    persNr = p;
}

void Person::setSkoNr(int s)
{
    skoNr = s;
}

// Överlagring av < operatorn
bool Person::operator<(const Person &p) const
{
    bool eq = false;

    if(name == p.getName())
    {
        eq = (address) < (p.getAddress());
    }
    else
    {
        eq = (name) < (p.getName());
    }

    return eq;
}

// Överlagring av == operatorn
bool Person::operator ==(const Person &p) const
{
    return name == p.getName();
}

// Avgränsare för utskrift till fil
const char DELIM='|';

// Överlagring av << utskriftsoperatorn
std::ostream &operator<<(ostream &os, const Person &p)
{
    os << p.getName() << p.getAddress() << p.getPersNr() << DELIM << p.getSkoNr();

    return os;
}

// Överlagring av >> inmatningsoperatorn
std::istream &operator>>(istream &is, Person &p)
{
    Name n;
    Address a;
    string s;

    is >> n;
    p.setName(n);

    is >> a;
    p.setAddress(a);

    getline(is, s, DELIM);
    p.setPersNr(s);

    // Strängström för att kunna använda getline på en int och sen
    // omvandla strängen till en integer
    getline(is, s);
    int skonr = 0;
    stringstream skostream(s);
    skostream >> skonr;
    p.setSkoNr(skonr);

    return is;
}
