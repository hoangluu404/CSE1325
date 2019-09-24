#include "stock.h"
#include "locomotive.h"

Locomotive::Locomotive(double weight=80000,double power=13500):Stock::Stock(weight),_power{power}{
  _art={ // Locomotive
  "       * # @ ",
  "     . ______",
  "   _()_||__||",
  "  ( cse1325 |",
  " /-OO----OO''",
  "#############",
  };
};
double Locomotive::power(){return _power;}

