#include "stock.h"
#include "locomotive.h"
#include<iostream>
Locomotive::Locomotive(){
  _power=13500;
  Stock(80000);
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

