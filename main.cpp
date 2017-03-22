#include <iostream>
#include <string>

#include "problem.hpp"
#include "queens.hpp"
#include "solver.hpp"
#include "forward_checking.hpp"

using namespace std;

int main(){
  int n;
  cout<<"size of board: n=";
  cin>>n;
  
  problem* p = new queens(n);
  //solver* s = new solver(p); // default prune algorithm -- backtracking
  solver* s = new solver(p,new forward_checking(p)); // prune algorithm fwd chk
  s->solve();
  s->show_solutions();
  
  
  return 0;
}
