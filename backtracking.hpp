#ifndef BACKTRACKING_HPP
#define BACKTRACKING_HPP

#include "prune.hpp"

class backtracking : public prune{
public:
  backtracking(problem* p);
  ~backtracking();

  void prunning(node& n);
};


#endif //BACKTRACKING_HPP
