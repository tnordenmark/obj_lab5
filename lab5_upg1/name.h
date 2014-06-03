#ifndef NAME_H
#define NAME_H
#include <string>

class Name
{
    private:
        // Medlemsattribut
        std::string firstName;
        std::string lastName;

    public:
        // Standardkonstruktor
        Name();
        // Överlagrad konstruktor
        Name(std::string fn, std::string ln);

        // Setters
        void setFirstName(std::string fn);
        void setLastName(std::string ln);

        // Getters inline
        std::string getFirstName() const {return firstName;}
        std::string getLastName() const {return lastName;}

        // Överlagring av operatorer
        bool operator<(const Name &name) const;
        bool operator==(const Name &name) const;
};

// Överlagring av operatorer för utskrift och inläsning
std::ostream &operator<<(std::ostream &os, const Name &n);
std::istream &operator>>(std::istream &is, Name &n);

#endif // NAME_H
