#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include "paralel.hpp"
#include "rectangle.hpp"

struct Domain {
  Domain()
      : xmin(0),
        xmax(120),
        x_exchange_min(40),
        x_exchange_max(80),
        y_bot_min(0.5),
        y_bot_max(1.0),
        y_wall_min(1.0),
        y_wall_max(1.5),
        y_top_min(1.5),
        y_top_max(2.0),
        x_range(xmin, xmax),
        y_bot_range(y_bot_min, y_bot_max),
        y_wall_range(y_wall_min, y_wall_max),
        y_top_range(y_top_min, y_top_max),
        exchange_range(x_exchange_min, x_exchange_max),
        bot(x_range, y_bot_range),
        wall(exchange_range, y_wall_range),
        top(x_range, y_top_range){};

  Domain(const Paralel &paralel) : Domain() {
    double x_length = (top.xmax() - top.xmin()) / paralel.n_procs();

    double _min = x_length * paralel.my_rank() + top.xmin();

    double _max = x_length + _min;

    top = Rectangle(Interval(_min, _max), y_top_range);
    wall = Rectangle(Interval(_min, _max), y_wall_range);
    bot = Rectangle(Interval(_min, _max), y_bot_range);
  }

 private:
  double xmin, xmax;

  double x_exchange_min, x_exchange_max;

  double y_bot_min, y_bot_max;
  double y_wall_min, y_wall_max;
  double y_top_min, y_top_max;

  Interval<double> x_range;

  Interval<double> y_bot_range;
  Interval<double> y_wall_range;
  Interval<double> y_top_range;

  Interval<double> exchange_range;

 public:
  Rectangle bot;
  Rectangle wall;
  Rectangle top;
};

#endif