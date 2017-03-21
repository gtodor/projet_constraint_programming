#ifndef problem_hpp
#define problem_hpp

#include <vector>
#include <string>
#include "domaine.hpp"

/*
  this class is used to create/define the problem: constraints & domains 
  plus initial data if necessary
*/
class problem{
private:
  std::string name;
  
protected:
  std::vector<domaine> domaines;

public:
  problem(std::string name);
  virtual ~problem();
  
  /*
   *return domaines
   */
  std::vector<domaine>& get_domaines();

  /*
   *return number of variables of the problem
   */
  unsigned int nb_vars();
  /*
   *defines the domains of each variable in the problem
   *should be implemented by each child class
   */
  virtual void define_domains()=0;
  /*
   *return true if the constraints are satisfied, or false if not
   *should be implemented by each child class
   */ 
  virtual bool check_constraints(std::vector<domaine>& n)=0;

  virtual bool check_constraints(int ai, int indai, int aj, int indaj ) = 0;
}; 

#endif //problem_hpp
