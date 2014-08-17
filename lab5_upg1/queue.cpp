// Defintionsfil
// Filnamn: queue.cpp
//---------------------------------------------------------------------------
// Nodeklassen placeras i cpp-filen för att den ska bli åtkomlig ENBART för
// klasserna QList och QIterator. På detta sätt kan datamedlemmarna göras
// public.
#include <iostream>
#include <fstream>
#include "queue.h"
#include "func.h"
using namespace std;

class Node
{
    public:
        Node *next;
        Item data;
        Node (Node *n, Item newData) : next(n), data(newData) {}
};

// Standardkonstruktor
QIterator::QIterator()
{
    node = nullptr;
}

// Överlagrad konstruktor
QIterator::QIterator(Node *n)
{
    node = n;
}

// Överlagrad * operator (dereferens)
Item &QIterator::operator*() const
{
    return node->data;
}

// Överlagrad ++(prefix) operator
QIterator &QIterator::operator++()
{
    node = node->next;

    return *this;
}

// Överlagrad ++(suffix) operator
QIterator QIterator::operator++(int)
{
    QIterator temp = *this;
    ++(*this);

    return temp;
}

// Överlagrad != operator
bool QIterator::operator!=(const QIterator &qi) const
{
    return (node != qi.node);
}

// Destruktor
QList::~QList()
{
    while(!isEmpty())
    {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
}

// Lägg till en ny node sist i kön
void QList::enque(Item item)
{
    Node *pNew = new Node(0, item);

    if(isEmpty())
        first = pNew;
    else
        last->next = pNew;
    last = pNew;
}

// Radera första noden i kön
bool QList::deque(Item &item)
{
    if(isEmpty())
        return false;

    Node *n = first;
    item = n->data;
    first = first->next;

    if(isEmpty())
        last = nullptr;

    delete n;

    return true;
}

// Radera en specifik node
bool QList::del(Item item)
{
    // Om kön är tom, return false
    if(isEmpty())
        return false;

    // Skapa noder som behövs
    Node *curr, *prev;

    // Sätt föregående och aktuell nod till first (huvudet)
    prev = curr = first;

    // Så länge curr inte är NULL och det inte blivit träff på eftersökt persnr
    while((curr != nullptr) && (curr->data.getPersNr() != item.getPersNr()))
    {
        // Sätt föregående till nuvarande
        prev = curr;
        // Och nuvarande till nuvarandes nästa nod
        curr = curr->next;
    }

    // Om curr är första nod
    if(curr == first)
    {
        // Sätt first till firsts nästa nod
        first = first->next;
    }
    else
    {
        // Sätt föregåendes nästa nod till aktuell nods nästa nod
        prev->next = curr->next;

        // Om aktuell nods nästa är NULL, dvs. aktuell nod = sista nod
        if(curr->next == nullptr)
            last = prev;
    }

    delete curr;

    return true;
}

// Är listan tom? Dvs. är första noden NULL?
bool QList::isEmpty() const
{
    return first == nullptr;
}


// Sökfunktion som returnerar en pekare till objektet som eftersöks
Node *QList::searchNode(string searchItem) const
{
    // Skapa en pekare till första noden
    Node *p = first;

    // Så länge p inte är NULL
    while(p != nullptr)
    {
        // Om persnrdatan i en node matchar searchItem
        if(p->data.getPersNr() == searchItem)
            // Returnera en pekare till noden
            return p;

        p = p->next;
    }

    return p;
}
