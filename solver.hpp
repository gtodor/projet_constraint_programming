#ifndef solver_hpp
#define solver_hpp

#include <string>
#include "prune.hpp"
#include "problem.hpp"

class solver{
private:
  prune* prune_algo;//what prune algoritm we want to use
  problem* p;// reference to the problem

public:
  solver(problem* p);
  solver(problem* p, std::string prune_algo);
  ~solver();

  //return implemented prune algorithm names 
  std::string get_prune_algos();

  //resolvs the problem by branch and prune algorithm
  void solve();

  //finds the next solution from current state  
  void step_solve();

  //print the solutions of the problem
  void show_solutions();
  
};

#endif // solver_hpp
