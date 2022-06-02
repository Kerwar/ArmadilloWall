#ifndef GRID_HPP
#define GRID_HPP

#include "interval.hpp"


struct Grid {
 public:
  Grid(const Interval<double> &_x_range,const  Interval<double> &_y_range):x_range_(_x_range), y_range_(_y_range) {};

  private:
  Interval<double> x_range_, y_range_;

};

#endif