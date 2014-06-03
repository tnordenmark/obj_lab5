#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "name.h"
#include "address.h"

class Person
{
    private:
        // Medlemsdattribut
        Name name;
        Address address;
        std::string persNr;
        int skoNr;

    public:
        // Standardkonstruktor
        Person();
        // Överlagrad konstruktor
        Person(Name n, Address a, std::string p, int s);

        // Setters
        void setName(Name n);
        void setAddress(Address a);
        void setPersNr(std::string p);
        void setSkoNr(int s);

        // Getters
        Name getName()const {return name;}
        Address getAddress()const {return address;}
        std::string getPersNr()const {return persNr;}
        int getSkoNr()const {return skoNr;}

        // Överlagring av klassens operatorer
        bool operator<(const Person &p) const;
        bool operator ==(const Person &p) const;
};

// Överlagring av operatorer för utskrift och inläsning
std::ostream &operator<<(std::ostream &os, const Person &p);
std::istream &operator>>(std::istream &is, Person &p);

#endif // PERSON_H
