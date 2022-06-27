#include "paralel.hpp"

Paralel::Paralel(const int &_my_rank, const int &_n_procs)
    : my_rank_(_my_rank),
      n_procs_(_n_procs),
      my_left_(my_rank_-- >= 0 ? my_rank_-- : MPI_PROC_NULL),
      my_right_(my_rank_++ < n_procs_ ? my_rank_++ : MPI_PROC_NULL) {}

Paralel::~Paralel() {}