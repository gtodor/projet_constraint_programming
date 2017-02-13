#include <iostream>
#include <string>
#include "solver.hpp"
#include "domaine.hpp"
#include "node.hpp"

using namespace std;

solver::solver(problem* p): p(p), pr_alg(new prune(p)), prune_algo("backtracking"){

}

solver::solver(problem* p, string prune_algo): p(p), pr_alg(new prune(p)){
if(get_prune_algos().find(prune_algo) == string::npos){
  throw std::invalid_argument("this prune_algo does not exist: use get_prune_algos for list of implemented prune algorithms");
 }else{
  this->prune_algo = prune_algo;
 }
}

solver::~solver(){
  delete pr_alg;
  delete p;
}

string solver::get_prune_algos(){
  return "backtracking;";
}

void solver::solve(){
  vector<node> nodes;
  node n1(p->nb_vars());
  for(unsigned int i=0; i<p->nb_vars();i++){
    n1[i] = (p->get_domaines())[i];
  }
  nodes.push_back(n1);
  while(!nodes.empty()){
    node nfirst = nodes[0];
    nodes.erase(nodes.begin());
    pr_alg->simple_prune(nfirst);//just check constraints
    if(!nfirst.is_empty()){
      if(nfirst.is_solution()){
	solutions.push_back(nfirst);
      }else{
	int min = nfirst.smallest_domaine();
	if(min == -2){
	  continue;
	}
	for(unsigned int i=0; i<nfirst[min].size(); i++){
	  node ncopy = nfirst;
	  ncopy[min].remove_all();
	  domaine d(1);
	  d[0] = nfirst[min][i];
	  ncopy[min] = d;
	  nodes.push_back(ncopy);
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
