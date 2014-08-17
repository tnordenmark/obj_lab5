#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address
{
    private:
        // Medlemsattribut
        std::string street;
        std::string postalno;
        std::string city;

    public:
        // Standardkonstruktor
        Address();
        // Överlagrad konstruktor
        Address(std::string s, std::string p, std::string c);

        // Setters
        void setStreet(std::string s);
        void setPostalNo(std::string p);
        void setCity(std::string c);

        // Getters inline
        std::string getStreet()const {return street;}
        std::string getPostalNo()const {return postalno;}
        std::string getCity()const {return city;}

        // Överlagrade operatorer
        bool operator<(const Address &a) const;
        bool operator==(const Address &a) const;
};

// Överlagring av operatorer för inläsning och utskrift
std::ostream &operator<<(std::ostream &os, const Address &a);
std::istream &operator>>(std::istream &is, Address &a);

#endif // ADDRESS_H
