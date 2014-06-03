#ifndef HOUSINGQ_H
#define HOUSINGQ_H
#include <string>
#include "queue.h"

class HousingQ
{
    private:
        QList que;
        int nrpers;
        std::string filename;

        void showMenu();
        int menuChoice();
        void addPersonToQue(QList &q);
        void offerHousing(QList &q);
        void printHousingQue(QList &q);
        int indexOf(const std::string &persnr, QList &q) const;
        int sizeOfQue(QList &q);
        void printPerson(QList &q);
        void delPerson(QList &q);
        void saveToFile(QList &q);
    public:
        HousingQ();
        int run();
};

#endif // HOUSINGQ_H
