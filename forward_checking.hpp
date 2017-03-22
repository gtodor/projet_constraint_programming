#ifndef FORWARD_CHECKING_HPP
#define FORWARD_CHECKING_HPP

#include "prune.hpp"

class forward_checking : public prune{
public:
  forward_checking(problem* p);
  ~forward_checking();

  void prunning(node& p);
};



#endif //FORWARD_CHECKING_HPP
