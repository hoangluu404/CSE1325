#include<iostream>
#include<vector>
#include<iomanip>
#include "stock.h"
#include "locomotive.h"
#include "coach.h"
#include "train.h"

int main(){
Train train;
Locomotive locomotive;
Coach coach;
int input=0;
do{
  std::cout<<"================================"<<std::endl;
  std::cout<<"  Hoang Luu Express 1000969998  "<<std::endl;
  std::cout<<"================================"<<std::endl;
  std::cout<<"\n"<<train.to_art()<<std::endl;



  std::cout<< "\n1 - Add a locomotive\n2 - Add an empty coach\n9 - Clear the train"<<std::endl;
  std::cout<<"0 - Exit\n\nCommand?\n" <<std::endl;

  std::cin>>input;

  if(input==1)
	train.add_locomotive(locomotive);
  else if(input==2)
	train.add_coach(coach);
  else if(input==9)
	train = Train();




}while(input!=0);










return 0;
}
