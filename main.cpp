#include <armadillo>
#include <iostream>

#include "grid.hpp"
#include "mpi.h"
#include "numericalparam.hpp"
#include "paralel.hpp"
#include "physicsparam.hpp"

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);

  int my_rank, n_procs;

  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);

  Paralel paralel(my_rank, n_procs);

  PhysicsParam physics_param;
  NumericalParam numerical_param;

  Grid mainGrid(numerical_param.N, numerical_param.M, physics_param.domain);

  MPI_Finalize();
}