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
        Node *searchNode(std::string searchItem) const;
    public:
        QList() : first(0), last(0) {}
        ~QList();
        void enque(Item item);
        bool deque(Item &item);
        bool del(Item item);
        bool isEmpty() const;
        QIterator begin() const {return QIterator(first);}
        QIterator end() const {return QIterator(nullptr);}
};

#endif // QUEUE_H
