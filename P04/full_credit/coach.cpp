#include "stock.h"
#include  "coach.h"
#include<iostream>
Coach::Coach(){std::cout<<"Added Coach"<<std::endl;
  Stock(28000);
  _art = { // Coach
  "               ",
  " ______________",
  " | [] [] [] []|",
  " |             ",
  "='OO--------OO'",
  "###############",
};
};
void Coach::add_passengers(int passengers){_passengers=passengers;}
double Coach::weight(){return Stock::weight()+_passengers*60;}
