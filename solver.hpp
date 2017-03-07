#ifndef solver_hpp
#define solver_hpp

#include <string>
#include <vector>
#include "node.hpp"
#include "prune.hpp"
#include "problem.hpp"

class solver{
private:
  problem* p;// reference to the problem
  prune* pr_algo;//what prune algoritm we want to use
  std::vector<node> solutions;

public:
  solver(problem* p);
  solver(problem* p, prune* prune_algo);
  ~solver();


  /*
   *solves the problem using a branch and prune algorithm
   *the algorithm is implemented by following the pseudo-code from the project subject
   */
  void solve();

  /*
   *finds the next solution from the current state of the variables/domains
   */
  void step_solve();

  /*
   *prints the solutions of the problem
   */
  void show_solutions();
  
};

#endif // solver_hpp
