#ifndef STOCK_H
#define STOCK_H
#include<vector>
#include<string>
#include<cmath>

class Stock{
public:
  Stock();
  Stock(double weight);
  virtual double weight();
  std::string ascii_art(int row);
protected:
  std::vector<std::string> _art;
private:
  double _weight;
};

#endif