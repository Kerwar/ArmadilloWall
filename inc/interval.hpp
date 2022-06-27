#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <iostream>

#include "equals.hpp"

template <class T>
struct Interval {
 public:
  Interval(const T &_min, const T &_max) : imin_(_min), imax_(_max){};

 private:
  T imin_, imax_;

 public:
  inline T imin() const { return imin_; };
  inline T imax() const { return imax_; };
  inline bool in(const T &v) const { return imin_ <= v && v <= imax_; };
  inline T length() const { return imax_ - imin_; };

  friend inline bool operator==(const Interval<T> &lhs,
                                const Interval<T> &rhs) {
    return equals(lhs.imin(), rhs.imin()) && equals(lhs.imax(), rhs.imax());
  };
  friend inline bool operator!=(const Interval<T> &lhs,
                                const Interval<T> &rhs) {
    return !(lhs == rhs);
  };

  friend std::ostream &operator<<(std::ostream &output, const Interval &I) {
    output << "[" << I.imin_ << ", " << I.imax_ << "]";
    return output;
  }
};

#endif