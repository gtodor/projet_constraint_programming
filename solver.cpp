#include <iostream>
#include <string>
#include <stack>
#include "solver.hpp"
#include "domaine.hpp"
#include "node.hpp"
#include "backtracking.hpp"


using namespace std;

solver::solver(problem* p): p(p), pr_algo(new backtracking(p)){
}

solver::solver(problem* p, prune* prune_algo): p(p), pr_algo(prune_algo){
  
}

solver::~solver(){
  delete pr_algo;
  delete p;
}


void solver::solve(){
  stack<node> nodes;
  node n1(p->get_domaines());
  nodes.push(n1);
  while(!nodes.empty()){
    node nfirst = nodes.top();
    //nodes.erase(nodes.begin());
    nodes.pop();
    //nfirst.print_node();
    pr_algo->prunning(nfirst);
    //nfirst.print_node();
    if(!nfirst.is_empty()){
      if(nfirst.is_solution()){
	solutions.push_back(nfirst);
      }else{
	int min = nfirst.smallest_domaine();
	if(min == -2){
	  continue;
	}
	unsigned int sz = nfirst[min].size();
	for(unsigned int i=0; i<sz; i++){
	  node ncopy = nfirst;
	  domaine d;
	  d.push_back(nfirst[min].head());
	  ncopy[min] = d;
	  nfirst[min].pop_front();
	  ncopy.print_node();
	  nodes.push(ncopy);
	}
      }
    }
    else{
      
    }
  }
}

void solver::show_solutions(){
  cout<<"LIST SOLUTIONS: "<<endl;
  for(unsigned int i=0;i<solutions.size();i++){
    solutions[i].print_node();
  }
}
