#include "stock.h"
#include "locomotive.h"
#include "coach.h"
#include "train.h"
#include<iostream>
void Train::add_locomotive(Locomotive& locomotive){_locomotives.push_back(&locomotive);}
void Train::add_coach(Coach& coach){_coaches.push_back(&coach);}
double Train::speed(double minutes){
  int total_power=0;
  int total_weight=0;
  total_power=_locomotives.size()*13500;
  total_weight=_locomotives.size()*80000+_coaches.size()*80000;
  /*for(int i=0;i<_locomotives.size();i++){
    total_power+=_locomotives[i]->power();
    total_weight+=_locomotives[i]->weight();
  }
  for(int i=0;i<_coaches.size();i++)
    total_weight+=_coaches[i]->weight();
  */
  return std::sqrt(2*total_power*minutes*60/total_weight);
}
std::string Train::to_art() {
  std::string str;
  
  for(int row=0;row<6;row++){
    for(int i=0;i<_locomotives.size();i++)
      str+=_locomotives[i]->ascii_art(row);
    for(int i=0;i<_coaches.size();i++)
      str+=_coaches[i]->ascii_art(row);
    str+="\n";
  }

return str;
}

std::ostream& operator<<(std::ostream& os, const Train& train)
{
    for(int row=0;row<6;row++){
    for(int i=0;i<_locomotives.size();i++)
      os<<this->_locomotives[i]->ascii_art(row);
    for(int i=0;i<_coaches.size();i++)
      os <<this->coaches[i]->ascii_art(row);
    os<<"\n";
  }
    return os;
}





