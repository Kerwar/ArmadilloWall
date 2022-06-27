#include "catch2/catch_all.hpp"
#include "equals.hpp"
#include "domain.hpp"

TEST_CASE("Initialization of domain", "domain") {
  Domain domain;
  
  Rectangle botRect(Interval(0.0,120.0), Interval(0.5,1.0));
  Rectangle wallRect(Interval(40.0,80.0), Interval(1.0,1.5));
  Rectangle topRect(Interval(0.0,120.0), Interval(1.5,2.0));

  CHECK(domain.bot == botRect);
  CHECK(domain.wall == wallRect);
  CHECK(domain.top == topRect);
}

TEST_CASE("Initialization of domain depending on nProcs", "domain") {
  Paralel paralel(2, 6);

  Domain domain(paralel);
  
  Rectangle botRect(Interval(40.0,60.0), Interval(0.5,1.0));
  Rectangle wallRect(Interval(40.0, 60.0), Interval(1.0,1.5));
  Rectangle topRect(Interval(40.0, 60.0), Interval(1.5,2.0));

  CHECK(domain.bot == botRect);
  CHECK(domain.wall == wallRect);
  CHECK(domain.top == topRect);
}