#include<string>
#include<cmath>
#include "line.h"

Line::Line(double x1,double y1, double x2, double y2): _x1{x1},_x2{x2},_y1{y1},_y2{y2} {};

std::string Line::to_string(){
	std::string s="(" + std::to_string(_x1) + "," + 		std::to_string(_y1) + ")" + "-"+ "(" + std::to_string(_x2) 			+ "," + std::to_string(_y2) + ")"; 
	return s;
}
double Line::length(){
	return sqrt( pow(_x1-_x2,2)  +  pow(_y1-_y2,2) );
}
