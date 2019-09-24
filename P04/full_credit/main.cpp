#include<iostream>
#include<vector>
#include<iomanip>
#include "stock.h"
#include "locomotive.h"
#include "coach.h"
#include "train.h"

int main(){
int w=7;
Train train;
Locomotive locomotive;
Coach coach;
int input=0;
do{
  std::cout<<"================================"<<std::endl;
  std::cout<<"  Hoang Luu Express 1000969998  "<<std::endl;
  std::cout<<"================================"<<std::endl;
  std::cout<<"\n"<<train.to_art()<<std::endl;
    std::cout<<std::setw(7)<<"Minutes"<<std::setw(w)<<"1"<<std::setw(w)<<"5"<<std::setw(w)<<"15"<<std::setw(w)<<"30"<<std::setw(w)<<"60"<<std::endl;
for(int i=0;i<5*w+7;i++) std::cout<<"-"; std::cout<<std::endl;
 std::cout<<std::setw(7)<<"m/s"<<std::setw(w)<<train.speed(1)<<std::setw(w)<< std::setprecision(3)<<train.speed(5)<<std::setw(w)<<train.speed(15)<<std::setw(w)<<train.speed(30)<<std::setw(w)<<train.speed(60)<<std::endl;
 
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
