#include "shelter.h"
#include <bits/stdc++.h> 
#include <string>
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
Shelter::Shelter(std::string name) : _name{name} { }
Shelter::Shelter(Shelter& shelter): _clients{shelter._clients} , _available{shelter._available}  		{}


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

//Shelter::Shelter(std::istream& ist){}


void Shelter::save() {
	std::ofstream ofs("default.mass");
	if(ofs.is_open()){


		//AVAILABLE ANIMALS
		for(int i=0; i<_available.size();i++){
			ofs << "available;" ;
			ofs << animal(i).family() <<";";
			ofs << animal(i).name() <<";";
			ofs << animal(i).int_breed() <<";";
			ofs << animal(i).gender() <<";";
			ofs << animal(i).age() <<"\n";
		}
		
		//LIST ALL CLIENTS
		for(int i=0; i< num_clients();i++){
			ofs << "client;";
			ofs << client(i)<<"\n";
		}


		//ADOPTED ANIMAL BY CLIENT NUMBER
		for(int i=0; i< num_clients();i++){
			//client ID


			for(int j=0; j< client(i).num_adopted(); j++  ){
				if(client(i).num_adopted()>0)	ofs << i << ";";
				ofs << client(i).animal(j).family() <<";";
				ofs << client(i).animal(j).name() <<";";
				ofs << client(i).animal(j).int_breed() <<";";
				ofs << client(i).animal(j).gender() <<";";
				ofs << client(i).animal(j).age() <<"\n";

			}
		}





	} else{
		return;	
	}
	ofs<<"end";
	ofs.close();
}

Shelter& Shelter::load(){

	std::ifstream ifs("default.mass");		//load default.mass
	Shelter* shelter = new Shelter("Just a Name");	//create a new shelter
	std::string line,temp;
	std::vector<std::string> tokens;


	//GET LINE
	while(std::getline(ifs, line, '\n') && !ifs.eof()){
		std::stringstream check(line);
		std::cout<<"LINE: "<<line<<std::endl;
		//BREAK LINE INTO PHRASE
		while(std::getline(check, temp, ';'))
			tokens.push_back(temp);		

		if(tokens[0]=="available"){	//AVAILABLE ANIMALS
			if(tokens[1]=="Dog"){
				Animal* animal = new Dog{dog_breeds[static_cast<int>(stoi(tokens[3]))], 
                                 	tokens[2],
                                 	( ( tokens[4] == "Male" ? Gender::MALE : Gender::FEMALE) == Gender::MALE ? 							Gender::MALE : Gender::FEMALE),
                                 	static_cast<int>(stoi(tokens[5]))};
				shelter->add_animal(*animal);


			}else if(tokens[1]=="Cat"){
				Animal* animal = new Cat{cat_breeds[static_cast<int>(stoi(tokens[3]))], 
                                 	tokens[2],
                                 	( ( tokens[4] == "Male" ? Gender::MALE : Gender::FEMALE) == Gender::MALE ? 							Gender::MALE : Gender::FEMALE),
                                 	static_cast<int>(stoi(tokens[5]))};
				shelter->add_animal(*animal);


			}else if(tokens[1]=="Rabbit"){
				Animal* animal = new Rabbit{rabbit_breeds[static_cast<int>(stoi(tokens[3]))], 
                                 	tokens[2],
                                 	( ( tokens[4] == "Male" ? Gender::MALE : Gender::FEMALE) == Gender::MALE ? 							Gender::MALE : Gender::FEMALE),
                                 	static_cast<int>(stoi(tokens[5]))};
				shelter->add_animal(*animal);


			}


		
		}else if(tokens[0]=="client"){	//CLIENTS INFO


		}else{				//ADOPTED ANIMALS


		}
	std::cout<<"___________________________"<<std::endl;
	for(int i=0; i<tokens.size(); i++)
		std::cout<<tokens[i]<<std::endl;
	while (!tokens.empty())
		tokens.pop_back();
	}


std::cout<<"END FILE"<<std::endl;
	return *shelter;
}









