#ifndef QUEUE_H
#define QUEUE_H
#include "person.h"
typedef Person Item;
class Node;
class QIterator
{
    private:
        Node *node;
    public:
        // Förvald konstruktor
        QIterator();
        // Initieringskonstruktor
        QIterator(Node *n);

        // *operatorn
        Item &operator*() const;
        // prefix ++i
        QIterator &operator++();
        // postfix i++
        QIterator operator++(int);
        // !=operatorn
        bool operator!=(const QIterator &qi) const;
};
//---------------------------------------------------------------------------
class QList
{
    private:
        Node *first, *last;
    public:
        QList() : first(0), last(0) {}
        ~QList();
        Node *searchNode(std::string searchItem) const;
        void enque(Item item);
        bool deque();
        bool del(Item item);
        bool isEmpty() const;
        QIterator begin() const {return QIterator(first);}
        QIterator end() const {return QIterator(nullptr);}
};

#endif // QUEUE_H
