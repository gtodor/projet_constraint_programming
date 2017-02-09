#ifndef problem_hpp
#define problem_hpp

//TODO maybe add function to read input data for the problem from extern file

/*
  this class is used to create/define the problem: constraints & domaines 
  plus initial data if necessary
*/
#include <vector>
#include "domaine.hpp"

class problem{
private:
  std::string name;
  std::vector<domaine> domaines;

public:
  problem(std::string name);
  virtual bool check_constraints()=0;
};

#endif //problem_hpp
