#ifndef __CAT_H
#define __CAT_H
//#include "gender.h"
#include "animal.h"
#include<string>
class Cat: public Animal{
public:
	Cat(/*Cat_breed breed,*/ std::string name/*, Gender gender*/, int age);
	~Cat();
	std::string breed();
private:
//	Cat_breed breed;
};

#endif