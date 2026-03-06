#include <iostream>

//typedef std::string text_t;
using text_t = std::string;

namespace f5{
  const double PI = 3.14159;
}

double circleCircumference(int radius) {
  return 2*f5::PI*radius;
}

int main() {
  std::cout << circleCircumference(10); 
  return 0;
}