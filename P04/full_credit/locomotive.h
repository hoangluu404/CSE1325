#ifndef LOCOMOTIVE_H
#define LOVOMOTIVE_H

class Locomotive: public Stock{
public:
  Locomotive(double weight, double power);
  double power();
private:
  double _power;
};

#endif