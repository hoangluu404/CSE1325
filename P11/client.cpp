#include "client.h"
#include <iostream>

Client::Client(std::string name, std::string phone, std::string email) : _name{name}, _phone{phone}, _email{email} {
std::vector<Animal*> adopted;
 }

std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << client._name  << "; "
        << client._phone << "; "
        << client._email;
    return ost;
}


void Client::adopt(Animal& animal){
  adopted.push_back(&animal);
}

int Client::num_adopted(){
  return adopted.size();
}
const Animal& Client::animal(int index){
  return *this->adopted[index];
}

std::string Client::name(){
	return _name;
}
