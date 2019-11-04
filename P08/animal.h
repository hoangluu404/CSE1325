#ifndef __ANIMAL_H
#define __ANIMAL_H
//#include "gender.h"
#include<string>


class Animal{
public:
	Animal(std::string name/*, Gender gender*/,int age);
	~Animal();
	std::string breed();
protected:
	std::string _name;
	//Gender _gender;
	int age;
};

#endif