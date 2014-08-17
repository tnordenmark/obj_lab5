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
        void addPersonToQue();
        void offerHousing();
        void printHousingQue();
        int indexOf(const std::string &persnr) const;
        int sizeOfQue();
        void printPerson();
        void delPerson();
        void saveToFile();
        void readFromFile();
    public:
        HousingQ();
        int run();
};

#endif // HOUSINGQ_H
