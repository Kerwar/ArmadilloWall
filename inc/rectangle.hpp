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
  
  inline double xmin() const { return ix_.imin(); }
  inline double xmax() const { return ix_.imax(); }
  inline double ymin() const { return iy_.imin(); }
  inline double ymax() const { return iy_.imax(); }
  
  inline double xlength() const { return ix_.length(); }
  inline double ylength() const { return iy_.length(); }
  
  inline bool in(const double &x, const double &y) {
    return ix_.in(x) && iy_.in(y);
  }

  friend inline bool operator==(const Rectangle &lhs, const Rectangle &rhs) {
    return lhs.ix_ == rhs.ix_ && lhs.iy_ == rhs.iy_;
  }
};

#endif