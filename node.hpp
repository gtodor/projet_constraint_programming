#ifndef node_hpp
#define node_hpp

#include <vector>
#include "domaine.hpp"

class node{
private:
  std::vector<domaine> domaines;
  bool solution;
public:
  node(int nr_vars);
  node(const node& n);

  node& operator=(node& other);
  domaine& operator[](unsigned int index);
  unsigned int nb_vars();
  void print_node();
  bool is_empty();
  bool is_solution();
  void set_solution(bool var);
  unsigned int smallest_domaine();
  std::vector<domaine> get_domaines();
  
};

#endif //node_hpp
