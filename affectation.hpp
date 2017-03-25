#ifndef AFFECTATION_HPP
#define AFFECTATION_HPP

#include "problem.hpp"

class affectation : public problem{
private:
  int** affect_matrix;
  int tasks;
  int machines;
public:
  /*
   *the affect_matrix is a n*m matrix containing only 1 and 0
   */
  affectation(int tasks, int machines);
  ~affectation();


  void define_domains();
  bool check_constraints(std::vector<domaine>& n);
  bool check_constraints(int ai, int indai, int aj, int indaj);
  void gen_affect_matrix();
};

#endif //AFFECTATION_HPP
