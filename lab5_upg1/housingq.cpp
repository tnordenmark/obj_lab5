#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include "housingq.h"
#include "func.h"
#include "queue.h"
using namespace std;

//------------------------------------------------------------------------------
// showMenu
//------------------------------------------------------------------------------
// Uppgift: Visar en huvudmeny
// Indata :
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::showMenu()
{
    cout << "=========================" << endl;
    cout << "        Huvudmeny" << endl;
    cout << "1. Ställ person i kö" << endl;
    cout << "2. Erbjud person bostad" << endl;
    cout << "3. Skriv ut kö" << endl;
    cout << "4. Skriv ut person" << endl;
    cout << "5. Ta bort person ur kö" << endl;
    cout << "6. Spara kö på fil" << endl;
    cout << "7. Avsluta" << endl;
    cout << "=========================" << endl;
}

//------------------------------------------------------------------------------
// menuChoice
//------------------------------------------------------------------------------
// Uppgift: Hanterar menyval för en huvudmeny
// Indata :
// Utdata : menuChoice returneras som en integer
//------------------------------------------------------------------------------
int HousingQ::menuChoice()
{
    // Lagra menyvalet
    int menuChoice;

    // Fråga efter och läs in menyvalet med teckenverifiering
    while ((cout << "Menyval: ")
             && (!(cin >> menuChoice)
             || menuChoice < 1
             || menuChoice > 7))
    {
        invalidChoice();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Returnera menyvalet som en integer
    return menuChoice;
}

//------------------------------------------------------------------------------
// addPersonToQue
//------------------------------------------------------------------------------
// Uppgift: Lägger till person i bostadskön
// Indata : &q (QList)
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::addPersonToQue(QList &q)
{
    // Skapa de objekt som behövs
    Person p;
    Name n;
    Address a;

    // Variabler för inmatad data
    string fname, lname, street, postalno, city, persnr, skonrstr;

    // Läs bort huvudmenyns newline
    cin.get();

    // Fråga efter, mata in och tilldela data till rätt objekts attribut
    cout << "Förnamn: ";
    getline(cin, fname);
    n.setFirstName(fname);

    cout << "Efternamn: ";
    getline(cin, lname);
    n.setLastName(lname);

    cout << "Gatuadress: ";
    getline(cin, street);
    a.setStreet(street);

    cout << "Postnr: ";
    getline(cin, postalno);
    a.setPostalNo(postalno);

    cout << "Stad: ";
    getline(cin, city);
    a.setCity(city);

    // Sätt Person-objektets "vanliga" variabler persNr och skoNr till rätt inmatad data
    cout << "Personnr: ";
    getline(cin, persnr);
    p.setPersNr(persnr);

    // Eftersom det är lite vanskligt att blanda cin >> och getline använder jag
    // getline till en temporär skonrsträng och omvandlar sen till int innan den
    // sparas i Person-objektet
    cout << "Skonr: ";
    getline(cin, skonrstr);
    int skonr = 0;
    stringstream skostream(skonrstr);
    skostream >> skonr;
    p.setSkoNr(skonr);

    // Tilldela objekten Name och Address i klassen Person sina objekt
    p.setName(n);
    p.setAddress(a);

    // Lägg hela personobjektet i kölistan
    q.enque(p);
}

//------------------------------------------------------------------------------
// offerHousing
//------------------------------------------------------------------------------
// Uppgift: Erbjuder bostad (tar bort första person ur kön) och skriver ut
//          information om aktuell person
// Indata : &q (QList)
// Utdata : Raderar person på köplats 1 samt skriver information
//------------------------------------------------------------------------------
void HousingQ::offerHousing(QList &q)
{
    QIterator qi = q.begin();

    // Om det går bra att ta bort personen först i kön
    if(q.deque())
    {
        // Skriv ut information om personen
        cout << endl;
        cout << "Följande person har erbjudits bostad: " << endl;
        cout << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName() << " - ";
        cout << (*qi).getPersNr() << endl << endl;
        // Uppdatera räknaren för antal personer
        nrpers--;
    }
    // Om kön är tom
    else
    {
        cout << endl;
        cout << "Kön är tom." << endl;
        cout << endl;
    }
}

//------------------------------------------------------------------------------
// printHousingQue
//------------------------------------------------------------------------------
// Uppgift: Skriver ut kölistan
// Indata : &q (QList)
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::printHousingQue(QList &q)
{
    // Om kön är tom
    if(q.isEmpty())
    {
        cout << endl;
        cout << "Kön är tom." << endl;
        cout << endl;
    }
    // Annars skriv ut listan
    else
    {
        // Räknare för köposition
        int quePos = 1;

        // Iterator för att iterera över kön
        QIterator qi;

        // Skriv ut antal personer i kön med hjälp av hjälpfunktionen sizeOfQue
        cout << endl << "Antal personer i kön: " << sizeOfQue(q) << endl << endl;

        // Iterera över kön och skriv ut samtliga noder i lättläst format
        for(qi = q.begin(); qi!=q.end(); qi++)
        {
            cout << "Plats i kön: " << quePos << endl;
            cout << "Namn: " << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName() << endl;
            cout << "Gatuadress: " << (*qi).getAddress().getStreet() << endl;
            cout << "Postadress: " << (*qi).getAddress().getPostalNo() << " " << (*qi).getAddress().getCity() << endl;
            cout << "Persnr: " << (*qi).getPersNr() << endl;
            cout << "Skonr: " << (*qi).getSkoNr() << endl;
            cout << endl;

            // Uppdatera räknaren för position i kön
            quePos++;
        }
    }
}

//------------------------------------------------------------------------------
// indexOf
//------------------------------------------------------------------------------
// Uppgift: Sök efter och returnera indexplats för en nod identifierad med
//          personnummer
// Indata : persnr (string), &q (QList)
// Utdata : idx (int)
//------------------------------------------------------------------------------
int HousingQ::indexOf(const string &persnr, QList &q) const
{
    // Skapa en iterator och en variabel för att lagra indexplatsen
    QIterator qi;
    int idx = 1;

    // Iterera över listan och returnera indexplats vid träff på personnummer
    for(qi = q.begin(); qi != q.end(); qi++)
    {
        // Jämför nodens persnr med söknyckeln
        if((*qi).getPersNr() == persnr)
            return idx;
        idx++;
    }

    // Returneras om ingen träff
    return -1;
}

//------------------------------------------------------------------------------
// sizeOfQue
//------------------------------------------------------------------------------
// Uppgift: Itererar över kön och räknar antalet noder
// Indata : &q (QList)
// Utdata : size (int)
//------------------------------------------------------------------------------
int HousingQ::sizeOfQue(QList &q)
{
    // Skapa en iterator och en variabel för att lagra antal noder
    QIterator qi;
    int size = 0;

    // Iterera över kön för att räkna antal noder
    for(qi = q.begin(); qi != q.end(); qi++)
        size++;

    return size;
}

//------------------------------------------------------------------------------
// printPerson
//------------------------------------------------------------------------------
// Uppgift: Skriver ut angiven person i listan
// Indata : &q (QList)
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::printPerson(QList &q)
{
    // Sträng för att lagra personnr
    string persnr;

    // Läs bort huvudmenyns newline
    cin.get();

    // Skriv meddelande om kön är tom
    if(q.isEmpty())
    {
        cout << endl;
        cout << "Kön är tom." << endl;
        cout << endl;
    }
    else
    {
        // Fråga efter personnr att skriva ut
        cout << "Mata in persnr att söka efter: ";
        getline(cin, persnr);

        // Skapa en iterator som pekar på noden med det eftersökta objektet
        QIterator qi;
        qi = q.searchNode(persnr);

        // Om p innehåller en adress till ett objekt (alltså inte är tom)
        if(qi != nullptr)
        {
            // Skriv ut personens köplats med hjälp av hjälpfunktionen indexOf
            cout << endl << "Plats i kön: " << indexOf(persnr, q) << endl;

            // Skriv ut personens information
            cout << "Namn: " << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName() << endl;
            cout << "Gatuadress: " << (*qi).getAddress().getStreet() << endl;
            cout << "Postadress: " << (*qi).getAddress().getPostalNo() << " " << (*qi).getAddress().getCity() << endl;
            cout << "Persnr: " << (*qi).getPersNr() << endl;
            cout << "Skonr: " << (*qi).getSkoNr() << endl;
            cout << endl;

        }
        else
            cout << endl << "Personen med persnr \"" << persnr << "\" finns inte i kön." << endl;
    }
}

//------------------------------------------------------------------------------
// delPerson
//------------------------------------------------------------------------------
// Uppgift: Raderar angiven person i listan
// Indata : &q (QList)
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::delPerson(QList &q)
{
    // Sträng för att lagra personnr
    string persnr;

    // Läs bort huvudmenyns newline
    cin.get();

    // Skriv meddelande om kön är tom
    if(q.isEmpty())
    {
        cout << endl;
        cout << "Kön är tom." << endl;
        cout << endl;
    }
    else
    {
        // Fråga efter personnr att radera
        cout << "Mata in persnr för person att radera: ";
        getline(cin, persnr);

        // Skapa ett iterator-objekt
        QIterator qi;

        // Iterera igenom listan
        for(qi = q.begin(); qi != q.end(); qi++)
        {
            if((*qi).getPersNr() == persnr)
            {
                // Avbryt loopen om qi står på rätt nod
                break;
            }
        }
        // Skicka med den derefererade noden, alltså objektet av typen Item, till
        // delete-funktionen och testa om delete-operationen slutfördes korrekt
        if(qi != nullptr)
        {
            q.del(*qi);

            cout << endl;
            cout << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName()
                 << " raderades ur listan." << endl;
            cout << endl;
        }
        // Annars felmeddelande
        else
        {
            cout << endl;
            cout << "Personen med persnr " << persnr << " kunde inte raderas." << endl;
            cout << endl;
        }
    }
}

//------------------------------------------------------------------------------
// saveToFile
//------------------------------------------------------------------------------
// Uppgift: Sparar listan på fil
// Indata : &q (QList)
// Utdata :
//------------------------------------------------------------------------------
void HousingQ::saveToFile(QList &q)
{
    // Skapa utfils-objekt
    fstream outFile("housingq.txt", ios::out);

    // Om det gick bra att öppna filen
    if(outFile.is_open())
    {
        // Skapa iterator för loopen
        QIterator qi;
        // Räknare för position i kön
        int quePos = 1;

        // Iterera över listan och skriv ut samtliga poster till utfilen
        for(qi = q.begin(); qi != q.end(); qi++)
        {
            outFile << "Plats i kön: " << quePos << endl;
            outFile << "Namn: " << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName() << endl;
            outFile << "Gatuadress: " << (*qi).getAddress().getStreet() << endl;
            outFile << "Postadress: " << (*qi).getAddress().getPostalNo() <<
                       " " << (*qi).getAddress().getCity() << endl;
            outFile << "Persnr: " << (*qi).getPersNr() << endl;
            outFile << "Skonr: " << (*qi).getSkoNr() << endl;
            outFile << endl;
            // Uppdatera positionsräknare
            quePos++;
        }
        // Ledtext är kul
        cout << endl;
        cout << "Listan skrevs till fil." << endl;
        cout << endl;
    }
    else
    {
        // I/O error, om filen inte kunde öppnas
        cout << endl;
        cout << "Kunde inte öppna filen." << endl;
        cout << endl;
    }

    // Stäng utfilen
    outFile.close();
}

// Standardkonstruktor
HousingQ::HousingQ()
{
    nrpers = 0;
    filename = "";
}

// Huvudfunktion som kör programmet
int HousingQ::run()
{
    // Skapa kö-objekt
    QList que;

    // Skapa testpersoner
    Person p1(Name("Arne", "Andersson"), Address("Storgatan 4", "83146", "Östersund"), "810512-8417", 44);
    Person p2(Name("Caesar", "Caligula"), Address("Kejsargatan 10", "55567", "Rom"), "141212-8415", 36);
    Person p3(Name("Daniel", "Dragan"), Address("Storgatan 10", "83146", "Östersund"), "651012-8245", 39);
    Person p4(Name("Beata", "Bertilsson"), Address("Esplanaden 5", "83132", "Östersund"), "610721-8216", 38);
    Person p5(Name("Bo", "Caligula"), Address("Torget 10", "531 42", "Landvetter"), "710101-8216", 38);

    // Lägg till testpersoner i kö
    que.enque(p1);
    nrpers++;
    que.enque(p2);
    nrpers++;
    que.enque(p3);
    nrpers++;
    que.enque(p4);
    nrpers++;
    que.enque(p5);
    nrpers++;

    // Lagra menyvalet
    int menu_choice;

    do
    {
        // Visa huvudmenyn
        showMenu();
        // Hämta menyvalet
        menu_choice = menuChoice();

        // Hantera huvudmenyns olika val
        switch(menu_choice)
        {
            case 1:
                // Lägg till person
                addPersonToQue(que);
                break;
            case 2:
                // Erbjud bostad till person först i kön och radera
                // densamme
                offerHousing(que);
                break;
            case 3:
                // Skriv ut kön
                printHousingQue(que);
                break;
            case 4:
                // Skriv ut given person
                printPerson(que);
                break;
            case 5:
                // Radera given person
                delPerson(que);
                break;
            case 6:
                // Spara kön till fil
                saveToFile(que);
                break;
            case 7:
                // Avsluta program
                cout << "Avslutar program..." << endl;
                return 0;
            default:
                // Bör inte hända, skriver felmeddelande
                invalidChoice();
        }
        // Upprepa så länge menyvalet inte är 3
    }while(menu_choice != 7);

    return 0;
}
