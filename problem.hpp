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
  
protected:
  std::vector<domaine> domaines;

public:
  problem(std::string name);
  virtual ~problem();
  std::vector<domaine> get_domaines();
  unsigned int nb_vars();
  virtual void define_domains()=0;
  virtual bool check_constraints(std::vector<domaine>& n)=0;
  virtual void print_solutions()=0;
};

#endif //problem_hpp
