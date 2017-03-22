#ifndef ARCCONSISTENCY_HPP
#define ARCCONSISTENCY_HPP

#include "prune.hpp"

class arcConsistency : public prune{
public:
  arcConsistency(problem* p);
  ~arcConsistency();

  void reviseAC(domaine& Di, domaine& Dj);
  bool HasSupport(int ai, int indai, domaine dj );
  void prunning(node& n);
};


#endif //ARCCONSISTENCY_HPP