#include <iostream>
#include <string>

#include "problem.hpp"
#include "queens.hpp"
#include "solver.hpp"

#include "domaine.hpp"
#include "node.hpp"

using namespace std;

int main(){
  int n;
  cout<<"size of board: n=";
  cin>>n;

  
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

  domaine l(3);
  l[0] = 5;
  l[1] = 90;
  l[2] = 45;
  cout<<"l = ";
  l.print_domaine();

  domaine m(0);
  cout<<"m = ";
  m.print_domaine();

  node nd(2);
  nd.print_node();
  nd[0] = j;
  nd[1] = d;
  nd.print_node();

  node nl(3);
  nl[0] = d;
  nl[1] = l;
  nl[2] = j;
  nl.print_node();

  nl[1][0]=1000;
  nl.print_node();

  node nn = nl;
  nl[2][3] = 1;
  nn.print_node();
  nl.print_node();

  cout<<endl<<endl;
  
  problem* p = new queens(n);
  p->print_solutions();
  //solver* s = new solver(p); // default prune algorithm -- backtracking
  //solver* s = new solver(p,"forward checking"); // prune algorithm fwd chk
  //s.solve();
  return 0;
}
