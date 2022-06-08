#ifndef GRID_HPP
#define GRID_HPP

#include "interval.hpp"
#include "rectangle.hpp"
#include <vector>

using std::vector;

struct Grid {
 public:
  Grid(const int &_N, const int &_M, const Rectangle &_domain)
      : N(_N),
        M(_M),
        NI(N+2),
        NJ(M+2),
        domain(_domain),
        DX(domain.xlength()/N),
        DY(domain.ylength()/M),
        x(NI, domain.xmin()),
        y(NJ, domain.ymin()),
        xc(NI, domain.xmin()),
        yc(NJ, domain.ymin()),
        xf(NI, 0),
        yf(NJ, 0) {
    setX();
    setY();
    setXC();
    setYC();
    setXF();
    setYF();
  };

  int N, M;
  int NI, NJ;
  Rectangle domain;
  
  double DX, DY;

  vector<double> x, y;
  vector<double> xc, yc;
  vector<double> xf, yf;

 private:
  void setX();
  void setY();
  void setXC();
  void setYC();
  void setXF();
  void setYF();
};

#endif