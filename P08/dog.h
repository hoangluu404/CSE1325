#ifndef __DOG_H
#define __DOG_H
#include<string>
#include "animal.h"
class Dog:public Animal{
public:
	Dog();
	Dog(/*Dog_breed breed, */std::string name/*, Gender gender*/, int age);
	~Dog();
	void family();
	void breed();
private:
//	Dog_breed _breed;


};

#endif