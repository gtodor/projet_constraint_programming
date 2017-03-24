#ifndef ARCCONSISTENCY_HPP
#define ARCCONSISTENCY_HPP

#include "prune.hpp"

class arcConsistency : public prune{
public:
  arcConsistency(problem* p);
  ~arcConsistency();

  void reviseAC(domaine& Di, int indi, domaine& Dj, int indj);
  bool HasSupport(int ai, int indai, domaine dj, int indj );
  void prunning(node& n);
};


#endif //ARCCONSISTENCY_HPP
