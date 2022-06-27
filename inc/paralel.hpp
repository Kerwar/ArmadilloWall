#ifndef PARALEL_HPP
#define PARALEL_HPP

#include "mpi.h"

class Paralel {
 private:
  int my_rank_, n_procs_;
  int my_left_, my_right_;

 public:
  Paralel(const int &_my_rank, const int &_n_procs);
  ~Paralel();

  inline int my_rank() const { return my_rank_; }
  inline int n_procs() const { return n_procs_; }
};

#endif