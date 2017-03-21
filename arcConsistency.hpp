#ifndef ARCCONSISTENCY_HPP
#define ARCCONSISTENCY_HPP

#include "prune.hpp"

class arcConsistency : public prune{
public:
  arcConsistency(problem* p);
  ~arcConsistency();

  void prunning(node& n);
  bool HasSupport(node& n );
  void arcConsistency::AC1(node& n);
};


#endif //ARCCONSISTENCY_HPP