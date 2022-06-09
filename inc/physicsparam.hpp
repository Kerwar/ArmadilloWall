#ifndef PHYSICSPARAM_HPP
#define PHYSICSPARAM_HPP

#include "rectangle.hpp"

struct PhysicsParam
{
  // Parameters that can be changed
  double xmin = 0;
  double xmax = 120;
  double ymin = 0.5;
  double ymax = 2;


  // Actual implementation of the parameters
  Interval<double> x_range(xmin, xmax);
  Interval<double> y_range(ymin, ymax);

  Rectangle domain(x_range, y_range);
};

#endif 