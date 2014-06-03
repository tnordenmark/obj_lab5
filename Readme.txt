Jag har totalt kört fast i pekarträsket och skickar in ett ofärdigt program så jag kan få lite
feedback och tips. Känner att jag måste få verifierat om jag är på rätt spår eller om programmet
är helt galet från början till slut. Det mesta fungerar utom funktionen för att radera en given
person.

De problem och funderingar jag har följer nedan:

housingq.cpp - void HousingQ::delPerson(QList &q)
=================================================

I den här funktionen kommer jag inte på något bra sätt att "koppla" ett objekt av typen Person
till datan i noden som returneras av sökfunktionen. QList::del(Item item) ska ju ha ett Item,
alltså ett objekt av typen Person. Har funderat lite på att försöka skriva en annan sökfunktion
som istället returnerar ett Item (alltså ett objekt av typen Person). Alternativt ändra del() så
att den tar en pekare till en nod som indata istället.


queue.cpp - Item &QIterator::operator*() const
==============================================

Är inte säker på om det är så enkelt som return node->data, misstänker att denna kommer till
användning i QList::del() för att radera en given person.

queue.cpp - QIterator &QIterator::operator++() och QIterator QIterator::operator++(int)
=======================================================================================

Samma sak här, är inte alls säker på hur dessa ska fungera.

queue.cpp - bool QIterator::operator!=(const QIterator &qi) const
=================================================================

Denna känns någorlunda rätt, men inte heller här är jag säker alls