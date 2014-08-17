Hej,

Börjar ju bli smått pinsamt det här. Pekardjungeln är inte helt lätt att hugga sig igenom innan den
berömda polletten trillat ned. Det känns dock som det går lite lättare nu när man haft en stund på
sig att smälta intrycken under sommaren. Nu tror jag att allt ska vara grönt. I alla fall de punkter
du behandlat i din feedback.

============================
void HousingQ::printPerson()
============================
Ersatt anropet till wrappern searchFor() ned loopen nedan som istället itererar över listan och
sätter qi till rätt nod vid träff på personnummer. Sen skriver jag ut informationen om personen
direkt med qi här eftersom ingenting raderars, utan bara eftersökts. Antar att det är så du menar?

for(qi = que.begin(); qi != que.end(); qi++)
{
    if((*qi).getPersNr() == persnr)
    {
        // Avbryt loopen om qi står på rätt nod
        break;
    }
}

=============================
void HousingQ::offerHousing()
=============================
Märkligt det där med att du får ett fel när du erbjuder en person bostad. Under Linux med gcc 4.9.1
fungerar det utmärkt för min del. Därför har jag inte upptäckt felet. Har dock genomfört ändringarna
enligt din feedback.

QIterator qi = que.begin();
Raderad då den ju inte behövs eftersom det är item som används.

cout << (*qi).getName().getFirstName() << " " << (*qi).getName().getLastName() << " - ";
cout << (*qi).getPersNr() << endl << endl;
Ändrad till att använda item för att skriva ut information om raderad person.

==========================
void HousingQ::delPerson()
==========================
Har ändrat så att eftersökt person sparas i item, och använder sen item för att skriva ut
informationen om personen efter att noden raderats.

for(qi = que.begin(); qi != que.end(); qi++)
{
    if((*qi).getPersNr() == persnr)
    {
        // Lagra eftersökt person i item
        item = *qi;
        // Avbryt loopen om qi står på rätt nod
        break;
    }
}

==========================================
*QList::searchFor(string searchItem) const
==========================================
Helt raderad från programmet.

---
Hälsningar
Thomas Nordenmark
