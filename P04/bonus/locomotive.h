#ifndef LOCOMOTIVE_H
#define LOVOMOTIVE_H

class Locomotive: public Stock{
public:
  Locomotive();
  double power();
private:
  double _power;
};

#endif