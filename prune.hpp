#ifndef prune_cpp
#define prune_cpp

#include "problem.hpp"
#include "node.hpp"

/*
 *class that contains prune methods for use in branchAndPrune algorithm 
 */
class prune{
private:
  problem* p;
  
public:
  prune(problem* p);
  ~prune();

  /*
   *method that only checks the constraints
   *param[in] reference to a node
   *if the constraints are satisfied and all domains size equal 1 this method sets the variable solution in node to true; else it empties the node
   */
  void simple_prune(node& n);  
  
};


#endif //prune_cpp
