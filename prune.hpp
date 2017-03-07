#ifndef prune_cpp
#define prune_cpp

#include "problem.hpp"
#include "node.hpp"

/*
 *class that contains prune methods for use in branchAndPrune algorithm 
 */
class prune{
protected:
  problem* p;
  
public:
  prune(problem* p);
  virtual ~prune();

  /*
   *method that only checks the constraints
   *param[in] reference to a node
   *if the constraints are satisfied and all domains size equal 1 this method sets the variable solution in node to true; else it empties the node
   */
  virtual void prunning(node& n)=0;  
  
};


#endif //prune_cpp
