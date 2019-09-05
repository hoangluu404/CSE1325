#include "line.h"
#include<iostream>

int main() {
    double x1,x2,y1,y2;
    std::cout << "Please enter 4 numbers to represent a line (x1,y1)-(x2,y2)\nSeperated by a space: ";
    std::cin >> x1 >> y1 >>x2 >>y2;
    Line line{x1, y1, x2, y2};
    std::cout << line.to_string() << " is "
              << line.length() << " long" << std::endl;
}
