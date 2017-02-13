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
  cout<<"inside solver::solve() method"<<endl;
  vector<node> nodes;
  node n1(p->nb_vars());
  for(unsigned int i=0; i<p->nb_vars();i++){
    n1[i] = (p->get_domaines())[i];
  }
  nodes.push_back(n1);
  while(!nodes.empty()){
    node nfirst = nodes[0];
    //nfirst.print_node();
    nodes.erase(nodes.begin());
    //nfirst.print_node();
    pr_alg->simple_prune(nfirst);//just check constraints
    //nfirst.print_node();
    if(!nfirst.is_empty()){
      if(nfirst.is_solution()){
	cout<<"nfirst is solution"<<endl;
	solutions.push_back(nfirst);
      }else{
	unsigned int min = nfirst.smallest_domaine();
	cout<<"min = "<<min<<endl;
	for(unsigned int i=0; i<nfirst[min].size(); i++){
	  node ncopy = nfirst;
	  ncopy[min].remove_all();
	  domaine d(1);
	  d[0] = nfirst[min][i];
	  ncopy[min] = d;
	  //ncopy.print_node();
	  nodes.push_back(ncopy);
	}
      }
    }
    else{
      cout<<"node is discarded"<<endl;
    }
  }
}

void solver::show_solutions(){
  cout<<endl<<endl<<"LIST SOLUTIONS: "<<endl;
  for(int i=0;i<solutions.size();i++){
    solutions[i].print_node();
  }
}
