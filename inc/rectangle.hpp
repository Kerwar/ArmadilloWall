#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "equals.hpp"
#include "interval.hpp"

struct Rectangle {
 public:
  Rectangle(Interval<double> _ix, Interval<double> _iy) : ix_(_ix), iy_(_iy) {}

 private:
  Interval<double> ix_, iy_;

 public:
  const Interval<double> xinterval() const { return ix_; }
  const Interval<double> yinterval() const { return iy_; }

  inline bool in(const double &x, const double &y){return ix_.in(x) && iy_.in(y);}
};

#endif