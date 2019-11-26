#ifndef __Cat_H
#define __Cat_H

#include "animal.h"

// List of CAT breeds, conversion to/from string and stream, and iteration
enum class Cat_breed {
    PERSIAN,
    RUSSIANBLUE,
    BENGAL,
    BRITISHSHORTHAIR,
    SIAMESE,
    MAINECOON,
    SPHYNX, 
    RAGDOLL,
    MUNCHKIN,
    SCOTTISHFOLD,
    BIRMAN,
    ABYSSINIAN,
};
constexpr Cat_breed cat_breeds[] = {
    Cat_breed::PERSIAN,
    Cat_breed::RUSSIANBLUE,
    Cat_breed::BENGAL,
    Cat_breed::BRITISHSHORTHAIR,
    Cat_breed::SIAMESE,
    Cat_breed::MAINECOON,
    Cat_breed::SPHYNX, 
    Cat_breed::RAGDOLL,
    Cat_breed::MUNCHKIN,
    Cat_breed::SCOTTISHFOLD,
    Cat_breed::BIRMAN,
    Cat_breed::ABYSSINIAN,
};
std::string to_string(const Cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);

// Class Cat with overrides for family and breed
class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    virtual ~Cat();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Cat_breed _breed;
};

#endif
