#ifndef __Rabbit_H
#define __Rabbit_H

#include "animal.h"

// List of Rabbit breeds, conversion to/from string and stream, and iteration
enum class Rabbit_breed {
    AMERICAN,
    BELGIANHARE,
    BLANCDEHOTOT,
    CALIFORNIAN,
    CHECKEREDGIANT,
    DUTCH,
    ENGLISHLOP, 
    ENGLISHSPOT,
    FLEMISHGIANT,
    FRENCHANGORA,
    ANGORA,
    HARLEQUIN,
};
constexpr Rabbit_breed rabbit_breeds[] = {
    Rabbit_breed::AMERICAN,
    Rabbit_breed::BELGIANHARE,
    Rabbit_breed::BLANCDEHOTOT,
    Rabbit_breed::CALIFORNIAN,
    Rabbit_breed::CHECKEREDGIANT,
    Rabbit_breed::DUTCH,
    Rabbit_breed::ENGLISHLOP, 
    Rabbit_breed:: ENGLISHSPOT,
    Rabbit_breed::FLEMISHGIANT,
    Rabbit_breed::FRENCHANGORA,
    Rabbit_breed:: ANGORA,
    Rabbit_breed::HARLEQUIN,
};
std::string to_string(const Rabbit_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed);

// Class Rabbit with overrides for family and breed
class Rabbit : public Animal {
  public:
    Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age);
    virtual ~Rabbit();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Rabbit_breed _breed;
};

#endif
