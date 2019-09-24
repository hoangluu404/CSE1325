#include "stock.h"
#include  "coach.h"

Coach::Coach(double weight=28000):Stock::Stock(weight){
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
