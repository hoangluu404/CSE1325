#ifndef __ANIMAL_H
#define __ANIMAL_H
//#include "gender.h"
#include<string>


class Animal{
public:
	Animal(std::string name/*, Gender gender*/,int age);
	~Animal();
	std::string family;
	std::string breed();
//	Gender gender();
	int age;
	std::string to_string();
protected:
	std::string _name;
//	Gender _gender;
	int _age;

};

#endif