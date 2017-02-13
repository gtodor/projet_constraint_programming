#include <iostream>
#include <string>

#include "problem.hpp"
#include "queens.hpp"
#include "solver.hpp"

using namespace std;

int main(){
  int n;
  cout<<"size of board: n=";
  cin>>n;
  
  problem* p = new queens(n);
  solver* s = new solver(p); // default prune algorithm -- backtracking
  s->solve();
  s->show_solutions();
  //solver* s = new solver(p,"forward checking"); // prune algorithm fwd chk
  return 0;
}
