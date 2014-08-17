#include <iostream>
#include "name.h"
using namespace std;

// Standardkonstruktor
Name::Name()
{
    firstName = "";
    lastName = "";
}

// Överlagrad konstruktor
Name::Name(string fn, string ln)
{
    firstName = fn;
    lastName = ln;
}

// Setters
void Name::setFirstName(string fn)
{
    firstName = fn;
}

void Name::setLastName(string ln)
{
    lastName = ln;
}

// Överlagring av < operatorn
bool Name::operator<(const Name &name) const
{
    bool eq = false;

    if(lastName == name.getLastName())
    {
        eq = (firstName) < (name.getFirstName());
    }
    else
    {
        eq = (lastName) < (name.getLastName());
    }

    return eq;
}

// Överlagring av == operatorn
bool Name::operator==(const Name &name) const
{
    bool eq = false;

    if(lastName == name.getLastName())
    {
        eq = (firstName) < (name.getLastName());
    }
    else
    {
        eq = (lastName) < (name.getLastName());
    }

    return eq;
}

// Avgränsare i fil
const char DELIM='|';

//Överlagring av << utskriftsoperatorn
ostream &operator<<(ostream &os, const Name &n)
{
    os << n.getFirstName() << DELIM << n.getLastName() << DELIM;

    return os;
}

// Överlagring av >> inläsningsoperatorn
istream &operator>>(istream &is, Name &n)
{
    string s;

    getline(is, s, DELIM);
    n.setFirstName(s);

    getline(is, s, DELIM);
    n.setLastName(s);

    return is;
}
