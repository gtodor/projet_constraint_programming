#include <iostream>
#include <string>

#include "problem.hpp"
#include "solver.hpp"

using namespace std;

int main(int argc, char** argv){
  int n;
  cout<<"size of board: n=";
  cin>>n;
  //problem* p = new queens(n);
  //solver* s = new solver(p); // default prune algorithm -- backtracking
  //solver* s = new solver(p,"forward checking"); // prune algorithm fwd chk
  //s.solve();
  //s.show_solutions();
  return 0;
}
