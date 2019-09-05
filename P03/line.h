
#include<string>
class Line{
  public:
	Line(double x1,double y1, double x2, double y2);
	std::string to_string();
	double length();
  private:
	double _x1,_x2,_y1,_y2;
};