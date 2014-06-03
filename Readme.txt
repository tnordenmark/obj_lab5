Först måste jag säga att jag hade förträngt att jag hade en lab kvar i kursen. Dock har
jag fått ordning på programmet vad jag kan se. Har skrivit om housingq.cpp och flyttat
alla funktioner med output från queue.cpp till housingq.cpp. Programmet segfaultar inte
längre om man försöker ta bort en användare som inte finns eller användare på specifika
platser i kön (först, sist etc).

Har även skrivit nya funktioner för indexOf() och sizeOfQue() i housingq.cpp den här
gången, samt städat upp koden och tagit bort en del andra funktioner. Loopar använder nu
QIterator för att iterera över listan och alla 0/NULL är ersatta med nullptr.

Dock har jag en reservation. Är inte helt säker på vad som menas angående att data ska 
returneras som en referensparameter i beskrivningen av deque-funktionen nedan. Ej heller
hur den ska skrivas. Är det meningen att man ska använda templates eller överlagring av
funktioner för att kunna returnera olika datatyper?

Namn: deque
Uppgift: Tar bort en nod i början av listan. Data för den person som ligger i noden
returneras via en referensdeklarerad parameter. Vidare returneras false om listan är tom
annars true
Indata: -
Utdata: false om listan är tom annars true. Item &item, data för den person som tas bort
från listan.

I övrigt verkar programmet fungera som det ska utan buggar.

Thomas Nordenmark
