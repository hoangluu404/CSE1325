#include<iostream>
#include<string>

int main(){

int x1=1,x2=2,x3=3,x4=4;
std::string s;
s="(" + std::to_string(x1) + "," + std::to_string(x2) + ")" + "(" + std::to_string(x3) + "," + std::to_string(x4) + ")";
std::cout<< s <<std::endl;

}
