#include "rabbit.h"

// Constructor / Destructor - note how delegation to base class works!
Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::~Rabbit() { }

// Overrides for pure virtual methods
std::string Rabbit::family() const {return "Rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Rabbit_breed& breed) {
    switch(breed) {
        case  Rabbit_breed::AMERICAN:        return "American";
        case  Rabbit_breed::BELGIANHARE:   return "Belgian Hare";
        case  Rabbit_breed::BLANCDEHOTOT:  return "Blanc De Hotot"; 
        case  Rabbit_breed::CALIFORNIAN:   return "Californian"; 
        case  Rabbit_breed::CHECKEREDGIANT:    return "Checkered Giant"; 
        case  Rabbit_breed::DUTCH:     return "Dutch"; 
        case  Rabbit_breed::ENGLISHLOP:     return "English Lop"; 
        case  Rabbit_breed::ENGLISHSPOT: return "English Spot"; 
        case  Rabbit_breed::FLEMISHGIANT:    return "Flemish Giant"; 
        case  Rabbit_breed::FRENCHANGORA:    return "French Angora"; 
        case  Rabbit_breed::ANGORA:      return "Angora"; 
        case  Rabbit_breed::HARLEQUIN:  return "Harlequin"; 
        default:                     return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
