#include "shelter.h"

Shelter::Shelter(std::string name) : _name{name} { }
std::string Shelter::name() {return _name;}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}

int Shelter::num_animals() {
	return _available.size();
}

Animal& Shelter::animal(int index) {
	return *(_available[index]);
}

void Shelter::add_client(Client& client) {
	_clients.push_back(client);
}

int Shelter::num_clients() {
	return _clients.size();
}

Client& Shelter::client(int index) {
	return _clients[index];
}

void Shelter::adopt(Client& client, Animal& animal){
	client.adopt(animal);

}

std::string Shelter::client_name(Client& client){
    return client.name();
}

std::string Shelter::animal_name(Animal& animal){
    return animal.name();
}

void Shelter::delete_animal(int index){
	_available.erase(_available.begin()+index);
}

Shelter::Shelter(std::istream& ist){}


void Shelter::save(std::ostream& ost) {
    ost << program_name << '\n' << program_version << '\n';
    ost << _name << std::endl;
    ost << _products.size() << std::endl;
    for(Product* f : _products) {ost << f->type() << std::endl; f->save(ost);}
    ost << _customers.size() << std::endl;
    for(Customer* c : _customers) c->save(ost);
    ost << _orders.size() << std::endl;
    for(Order* o : _orders) o->save(ost);
}
