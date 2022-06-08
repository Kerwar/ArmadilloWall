#include "catch2/catch_all.hpp"
#include "equals.hpp"
#include "grid.hpp"

using std::vector;
TEST_CASE("Initialization of grid", "grid") {
  Interval<double> x(-1, 2), y(0.5, 1.5);
  Rectangle rectangle(x, y);

  Grid grid(10, 20, rectangle);

  CHECK(grid.N == 10);
  CHECK(grid.M == 20);
  CHECK(grid.NI == 12);
  CHECK(grid.NJ == 22);
  CHECK(grid.domain == rectangle);
}

TEST_CASE("Grid faces", "grid") {
  Interval<double> x(0, 1), y(0.5, 1.5);
  Rectangle rectangle(x, y);

  Grid grid(10, 5, rectangle);

  vector<double> grid_in_x = {0, 0.1, 0.2, 0.3, 0.4, 0.5,
                              0.6,  0.7,  0.8,  0.9,  1, 1};

  vector<double> grid_in_y = {0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.5};

  CHECK(grid.x.size() == 12);
  CHECK(grid.y.size() == 7);

  for (vector<double>::size_type i = 0; i < grid_in_x.size(); i++) {
    INFO(i << " " << grid.x[i] << " " << grid_in_x[i]);
    CHECK(equals(grid.x[i], grid_in_x[i]));
  }

  for (vector<double>::size_type j = 0; j < grid_in_y.size(); j++)
  {
    INFO(j << " " << grid.y[j] << " " << grid_in_y[j]);
    CHECK(equals(grid.y[j], grid_in_y[j]));
  }
}

TEST_CASE("Grid Centers", "grid") {
  Interval<double> x(-1, 1), y(-0.5, 1.5);
  Rectangle rectangle(x, y);

  Grid grid(10, 5, rectangle);

  vector<double> grid_in_x = {-1,  -0.9, -0.7, -0.5, -0.3, -0.1,
                              0.1, 0.3,  0.5,  0.7,  0.9,  1};

  vector<double> grid_in_y = {-0.5, -0.3, 0.1, 0.5, 0.9, 1.3, 1.5};

  CHECK(grid.xc.size() == 12);
  CHECK(grid.yc.size() == 7);

  for (vector<double>::size_type i = 0; i < grid_in_x.size(); i++) {
    INFO(i << " " << grid.xc[i] << " " << grid_in_x[i]);
    CHECK(equals(grid.xc[i], grid_in_x[i]));
  }

  for (vector<double>::size_type j = 0; j < grid_in_y.size(); j++)
  {
    INFO(j << " " << grid.yc[j] << " " << grid_in_y[j]);
    CHECK(equals(grid.yc[j], grid_in_y[j]));
  }
}

TEST_CASE("Grid factors", "grid") {
  Interval<double> x(-1, 1), y(-0.5, 1.5);
  Rectangle rectangle(x, y);

  Grid grid(10, 5, rectangle);

  vector<double> grid_in_x = {0, 0.5, 0.5, 0.5, 0.5 , 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0};

  vector<double> grid_in_y = {0, 0.5, 0.5, 0.5, 0.5 , 1, 0};

  CHECK(grid.xc.size() == 12);
  CHECK(grid.yc.size() == 7);

  for (vector<double>::size_type i = 0; i < grid_in_x.size(); i++) {
    INFO(i << " " << grid.xf[i] << " " << grid_in_x[i]);
    CHECK(equals(grid.xf[i], grid_in_x[i]));
  }

  for (vector<double>::size_type j = 0; j < grid_in_y.size(); j++)
  {
    INFO(j << " " << grid.yf[j] << " " << grid_in_y[j]);
    CHECK(equals(grid.yf[j], grid_in_y[j]));
  }
}