#ifndef queens_hpp
#define queens_hpp

#include "problem.hpp"

class queens : public problem{
private:
  int size;
public:
  queens(int size);
  ~queens();
  bool check_constraints();
  void define_domains();
  void print_solutions();
};




#endif //queens_hpp
