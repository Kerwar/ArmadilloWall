#include "catch2/catch_all.hpp"

#include "rectangle.hpp"
#include "equals.hpp"

TEST_CASE("Initialization of rectangle", "rectangle") {
  Interval<double> ix(-1,2);
  Interval<double> iy(0,3);

  Rectangle rectangle(ix,iy);

  CHECK(rectangle.xinterval() == ix);
  CHECK(rectangle.yinterval() == iy);
}

TEST_CASE("Value is in rectangle", "rectangle") {
  Interval<double> ix(-1,2);
  Interval<double> iy(0,3);

  Rectangle rectangle(ix,iy);

  double x1 = -2;
  double x2 = -3;
  double x3 = -1;
  double x4 = 0;

  double y1 = 4;
  double y2 = 1;
  double y3 = -1;
  double y4 = 2;

  CHECK(!rectangle.in(x1,y1));
  CHECK(!rectangle.in(x2,y2));
  CHECK(!rectangle.in(x3,y3));
  CHECK(rectangle.in(x4,y4));

}