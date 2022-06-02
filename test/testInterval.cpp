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