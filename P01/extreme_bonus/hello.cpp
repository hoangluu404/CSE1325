#include<iostream>
#include<string>

int main(){
	std::string whoami;
	whoami=system("whoami");
	std::cout << "Hello " << whoami <<std::endl;

return 0;	

}
