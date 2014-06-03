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
