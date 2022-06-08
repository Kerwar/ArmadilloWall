#include "grid.hpp"

void Grid::setX() {
  for (int i = 1; i < NI - 1; i++) x[i] = x[i - 1] + DX;

  x[NI - 1] = x[NI - 2];
}

void Grid::setY() {
  for (int j = 1; j < NJ - 1; j++) y[j] = y[j - 1] + DY;

  y[NJ - 1] = y[NJ - 2];
}

void Grid::setXC() {
  for (int i = 1; i < NI; i++) xc[i] = (x[i - 1] + x[i]) * 0.5;
}

void Grid::setYC() {
  for (int j = 1; j < NJ; j++) yc[j] = (y[j - 1] + y[j]) * 0.5;
}

void Grid::setXF() {
  for (int i = 1; i < NI-1; i++) xf[i] = (x[i] - xc[i]) / (xc[i + 1] - xc[i]);
}

void Grid::setYF() {
  for (int j = 1; j < NJ-1; j++) yf[j] = (y[j] - yc[j]) / (yc[j + 1] - yc[j]);
}