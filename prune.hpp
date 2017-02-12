#ifndef prune_cpp
#define prune_cpp

#include "problem.hpp"
#include "node.hpp"

class prune{
private:
  problem* p;
  
public:
  prune(problem* p);
  ~prune();
  void simple_prune(node& n);  
  
};


#endif //prune_cpp
