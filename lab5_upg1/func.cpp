#include <iostream> // cout, cin
#include "func.h"
#include "name.h"
using namespace std;

//------------------------------------------------------------------------------
// invalidChoice
//------------------------------------------------------------------------------
// Uppgift: Skriver ut felmeddelande vid ogiltig inmatning
// Indata :
// Utdata : Funktionen skriver ut ett felmeddelande
//------------------------------------------------------------------------------
void invalidChoice()
{
    cout << "Ogiltigt val, mata in en siffra mellan 1 och 7." << endl;
}

//------------------------------------------------------------------------------
// printPerson
//------------------------------------------------------------------------------
// Uppgift: Underlättar utskrift av en eller flera personer
// Indata : Ett objekt av typen Person
// Utdata : Utskrift till skärm
//------------------------------------------------------------------------------
void printPers(const Person &p)
{
    cout << "Namn: " << p.getName().getFirstName() << " "
         << p.getName().getLastName() << endl;
    cout << "Gatuadress: " << p.getAddress().getStreet() << endl;
    cout << "Postadress: " << p.getAddress().getPostalNo()
         << " " << p.getAddress().getCity() << endl;
    cout << "Personnr: " << p.getPersNr() << endl;
    cout << "Skostorlek: " << p.getSkoNr() << endl;
}
