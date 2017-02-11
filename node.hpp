#ifndef node_hpp
#define node_hpp

#include <vector>
#include "domaine.hpp"

class node{
private:
  std::vector<domaine> domaines;

public:
  node(int nr_vars);
  node(const node& n);

  node& operator=(node& other);
  domaine& operator[](unsigned int index);
  unsigned int nb_vars();
  void print_node();
  
};

#endif //node_hpp
