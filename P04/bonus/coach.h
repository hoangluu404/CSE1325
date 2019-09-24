#ifndef COACH_H
#define COACH_H

class Coach:public Stock{
public:
  Coach();
  void add_passengers(int passengers);
  double weight() override;
private:
  int _passengers;
};

#endif