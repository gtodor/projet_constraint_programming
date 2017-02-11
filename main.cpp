#include <iostream>
#include <string>

#include "problem.hpp"
#include "solver.hpp"

//#include "domaine.hpp"

using namespace std;

int main(){
  int n;
  cout<<"size of board: n=";
  cin>>n;

  /*
  domaine d(n);
  cout<<"d = ";
  d.print_domaine();
  d[0]=2;
  d[1]=8;
  d[2]=89;
  cout<<"d = ";
  d.print_domaine();
  domaine k = d;
  cout<<"k = ";
  k.print_domaine();
  k[3] = 17;
  cout<<"k = ";
  k.print_domaine();
  cout<<"d = ";
  d.print_domaine();
  domaine j(12);
  cout<<"j = ";
  j.print_domaine();
  j = k;
  cout<<"j = ";
  j.print_domaine();
  j.remove(2);
  cout<<"j = ";
  j.print_domaine();
  cout<<"k = ";
  k.print_domaine();
  k.remove_all();
  cout<<"k = ";
  k.print_domaine();
  cout<<"j = ";
  j.print_domaine();
  cout<<"d = ";
  d.print_domaine();

  domaine l(1);
  cout<<"l = ";
  l.print_domaine();

  domaine m(0);
  cout<<"m = ";
  m.print_domaine();
  */

  
  //problem* p = new queens(n);
  //solver* s = new solver(p); // default prune algorithm -- backtracking
  //solver* s = new solver(p,"forward checking"); // prune algorithm fwd chk
  //s.solve();
  //s.show_solutions();
  return 0;
}
