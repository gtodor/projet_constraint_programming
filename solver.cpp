#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdio>
#include <ctime>
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
  clock_t start;
  start = clock();
  
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
	  nodes.push(ncopy);
	}
      }
    }
    else{
      
    }
  }
  execution_time = (clock() - start)/(double)CLOCKS_PER_SEC;
}

void solver::show_solutions(){
  if(solutions.size() < 10000){
    ofstream myfile;
    myfile.open("solutions.txt",ios::trunc);
    cout<<"LIST SOLUTIONS: "<<endl;
    for(unsigned int i=0;i<solutions.size();i++){
      solutions[i].print_node();
      myfile << solutions[i].to_string();
    }
    myfile.close();
    cout<<"There are "<<solutions.size()<<" solutions"<<endl;
  }else{
    cout<<"Too many solutions ("<<solutions.size()<<"): Find them in file 'solutions.txt' "<<endl;
    ofstream myfile;
    myfile.open("solutions.txt",ios::trunc);
    for(unsigned int i = 0; i<solutions.size(); i++){
      myfile << solutions[i].to_string();
    }
    myfile.close();
  }
  cout<<"the algorithm took "<<execution_time<<" sec"<<endl;
}
