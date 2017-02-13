#ifndef queens_hpp
#define queens_hpp

#include <vector>
#include "problem.hpp"
/*
 *this class represents the n queens problem
 */
class queens : public problem{
private:
  int size;
public:
  queens(int size);
  ~queens();
  
  /*
   *We use the discrete model to represent the n queens problem. The variable X1 represents for example the column where we should place the 1st queen. 
   */
  bool check_constraints(std::vector<domaine>& n);
  
  /*
   *Each variable has the same domain {0,1,...,size}
   */
  void define_domains();
};




#endif //queens_hpp
