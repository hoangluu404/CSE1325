#ifndef __CLIENT_H
#define __CLIENT_H

#include <string>
#include<vector>
#include "animal.h"

class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
    void adopt(Animal& animal);
    int num_adopted();
    const Animal& animal(int index);
	std::string name();
  private:
    std::string _name;
    std::string _phone;
    std::string _email;

	std::vector<Animal*> adopted;
};

#endif

