#ifndef node_hpp
#define node_hpp

#include <vector>
#include <string>
#include "domaine.hpp"

/*
 *class that is used to store informations about the current state of a problem
 */
class node{
private:
  std::vector<domaine> domaines;
  bool solution;
public:
  /*
   *param[in] the number of varibles of the problem
   *at initialization the node contains nr_vars empty domains
   */
  node(std::vector<domaine>& domaines);

  node(const node& n);
  /*
   *assignement operator used to copy one node to another
   */
  node& operator=(node& other);
  /*
   *compare two node
   */
  bool operator==(node& other);
  /*
   * we can acess each domain of the node like an array
   * ex: node n(3); n[1] represents the 2nd domain of the node
   */
  domaine& operator[](unsigned int index);
  /*
   *return number of variables/domains in the node
   */
  unsigned int nb_vars();

  /*
   *prints a graphic representation of a node
   */ 
  void print_node();

  /*
   *return true if every domain in node is empty
   */
  bool is_empty();
  /*
   *return true if this node corresponds to a solution of the problem
   */
  bool is_solution();
  /*
   *sets the variable solution at true if this node contain a solution
   */
  void set_solution(bool var);

  /*
   *return the index of the smallest domain in the node that has not a size of 1
   *if there is no such index (all domains have a size of 1) it returns a negative number irrelevant to the problem
   */
  int smallest_domaine();

  /*
   *return domaines
   */
  std::vector<domaine>& get_domaines();

  std::string to_string();
  
};

#endif //node_hpp
