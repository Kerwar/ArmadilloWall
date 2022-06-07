#include "catch2/catch_all.hpp"
#include "interval.hpp"
#include "equals.hpp"

TEST_CASE("Interval initialization", "Interval")
{
  Interval<double> interval(0,1);

  CHECK(equals(interval.imin(),0));
  CHECK(equals(interval.imax(),1));
}

TEST_CASE("Interval Length", "Interval")
{
  Interval<double> interval(0,1);

  CHECK(equals(interval.length(),1));

  Interval<double> interval2(-2,1);

  CHECK(equals(interval2.length(),3));
}

TEST_CASE("Interval equals", "Interval")
{
  Interval<double> interval1(0,1);
  Interval<double> interval2(-2,1);
  Interval<double> interval3(-2,1);

  CHECK(interval1 != interval2);
  CHECK(interval2 == interval3);
}

TEST_CASE("Value is in interval", "Interval")
{
  Interval<double> interval(3,10);
  double v1 = 1;
  double v2 = 3;
  double v3 = 6;
  double v4 = 10;
  double v5 = 10.0001;

  CHECK(!interval.in(v1));
  CHECK(interval.in(v2));
  CHECK(interval.in(v3));
  CHECK(interval.in(v4));
  CHECK(!interval.in(v5));
}