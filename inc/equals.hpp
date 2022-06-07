#ifndef EQUALS_HPP
#define EQUALS_HPP

#include <cmath>

inline bool equals(const double &a, const double &b){return std::abs(a-b) < 10E-8;}

#endif