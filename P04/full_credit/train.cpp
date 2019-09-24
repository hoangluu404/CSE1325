#include "stock.h"
#include "locomotive.h"
#include "coach.h"
class Train{
public:
  void add_locomotive(Locomotive& locomotive);
  void add_coach(Coach& coach);
  double speed(double minutes);
  std::string to_art();
private:
  std::vector<Locomotive*> _locomotives;
  std::vector<Coach*> _coaches;
};

void Train::add_locomotive(Locomotive& locomotive){_locomotives.push_back(&locomotive);}
void Train::add_coach(Coach& coach){_coaches.push_back(&coach);}
double Train::speed(double minutes){
  int total_power=0;
  int total_weight=0;
  for(int i=0;i<_locomotives.size();i++){
    total_power+=_locomotives[i]->power();
    total_weight+=_locomotives[i]->weight();
  }
  for(int i=0;i<_coaches.size();i++)
    total_weight+=_coaches[i]->weight();
  return std::sqrt(2*total_power*minutes*60/total_weight);
}
//std::string Train::to_art(){}





