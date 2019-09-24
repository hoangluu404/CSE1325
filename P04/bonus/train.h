#ifndef TRAIN_H
#define TRAIN_H

class Train{
public:
  void add_locomotive(Locomotive& locomotive);
  void add_coach(Coach& coach);
  double speed(double minutes);
  std::string to_art();
  friend std::ostream& operator<<(std::ostream& os, const Train& train);
private:
  std::vector<Locomotive*> _locomotives;
  std::vector<Coach*> _coaches;
};

#endif