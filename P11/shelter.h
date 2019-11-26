#ifndef __SHELTER_H
#define __SHELTER_H

#include "animal.h"
#include "client.h"
#include <vector>
#include <ostream>
#include <istream>

class Shelter {
  public:
    Shelter(std::string name);
    std::string name();

    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index); 

    void add_client(Client& client);
    int num_clients();
    Client& client(int index);


    std::string client_name(Client& client);
    std::string animal_name(Animal& animal);
    void delete_animal(int index);

    void adopt(Client& client, Animal& animal);


    Shelter(std::istream& ist);
    void save(std::ostream& ost);

  private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client>  _clients;
};

#endif

