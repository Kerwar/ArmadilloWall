#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include "equals.hpp"

template <class T>
struct Interval {
 public:
  Interval(const T &_min, const T &_max) : imin_(_min), imax_(_max){};

 private:
  T imin_, imax_;

 public:
  constexpr T imin() const { return imin_; };
  constexpr T imax() const { return imax_; };
  constexpr bool in(const T &v) const { return imin_ <= v && v <=imax_; };
  constexpr T length() const { return imax_ - imin_; };

  friend inline bool operator==(const Interval<T> &lhs, const Interval<T> &rhs) {return equals(lhs.imin(), rhs.imin()) &&  equals(lhs.imax(), rhs.imax());};
  friend inline bool operator!=(const Interval<T> &lhs, const Interval<T> &rhs) {return !(lhs==rhs);};
};

#endif