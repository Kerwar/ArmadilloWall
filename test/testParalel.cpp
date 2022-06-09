#include "catch2/catch_all.hpp"
#include "paralel.hpp"
#include "mpi.h"

TEST_CASE("Initialization of Paralel", "paralel") {
  Paralel paralel(0, 10);

  CHECK(paralel.my_rank() == 0);
  CHECK(paralel.n_procs() == 10);
  
}