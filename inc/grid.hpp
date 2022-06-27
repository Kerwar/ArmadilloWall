#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

#include "interval.hpp"
#include "rectangle.hpp"

using std::vector;

struct Grid {
 public:
  Grid(const int &_N, const int &_M, const Rectangle &_domain)
      : N(_N),
        M(_M),
        NI(N + 2),
        NJ(M + 2),
        domain(_domain),
        DX(domain.xlength() / N),
        DY(domain.ylength() / M),
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
  void inline setX();
  void inline setY();
  void inline setXC();
  void inline setYC();
  void inline setXF();
  void inline setYF();
};

void inline Grid::setX() {
  for (int i = 1; i < NI - 1; i++) x[i] = x[i - 1] + DX;

  x[NI - 1] = x[NI - 2];
}

void inline Grid::setY() {
  for (int j = 1; j < NJ - 1; j++) y[j] = y[j - 1] + DY;

  y[NJ - 1] = y[NJ - 2];
}

void inline Grid::setXC() {
  for (int i = 1; i < NI; i++) xc[i] = (x[i - 1] + x[i]) * 0.5;
}

void inline Grid::setYC() {
  for (int j = 1; j < NJ; j++) yc[j] = (y[j - 1] + y[j]) * 0.5;
}

void inline Grid::setXF() {
  for (int i = 1; i < NI - 1; i++) xf[i] = (x[i] - xc[i]) / (xc[i + 1] - xc[i]);
}

void inline Grid::setYF() {
  for (int j = 1; j < NJ - 1; j++) yf[j] = (y[j] - yc[j]) / (yc[j + 1] - yc[j]);
}

#endif