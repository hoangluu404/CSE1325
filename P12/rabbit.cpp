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

int to_int(const Rabbit_breed& breed) {
    switch(breed) {
        case  Rabbit_breed::AMERICAN:        return 1;
        case  Rabbit_breed::BELGIANHARE:   return 2;
        case  Rabbit_breed::BLANCDEHOTOT:  return 3; 
        case  Rabbit_breed::CALIFORNIAN:   return 4; 
        case  Rabbit_breed::CHECKEREDGIANT:    return 5; 
        case  Rabbit_breed::DUTCH:     return 6; 
        case  Rabbit_breed::ENGLISHLOP:     return 7; 
        case  Rabbit_breed::ENGLISHSPOT: return 8; 
        case  Rabbit_breed::FLEMISHGIANT:    return 9; 
        case  Rabbit_breed::FRENCHANGORA:    return 10; 
        case  Rabbit_breed::ANGORA:      return 11; 
        case  Rabbit_breed::HARLEQUIN:  return 12; 
        default:                     return 0;
    }
}


int Rabbit::int_breed() const { return to_int(_breed); };



