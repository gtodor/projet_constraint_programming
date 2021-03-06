#include "backtracking.hpp"
#include <vector>
#include <iostream>

using namespace std;

backtracking::backtracking(problem* p): prune(p){

}

backtracking::~backtracking(){
  
}

void backtracking::prunning(node& n){
  vector<domaine> d = n.get_domaines();
  bool sat = p->check_constraints(d);
  bool all1 = true;
  bool domaine_null = false;
  for(unsigned int i=0; i<n.nb_vars(); i++){
    if(n[i].size() != 1){
      all1=false;
      break;
    }
  }
  for(unsigned int i=0; i<n.nb_vars(); i++){
    if(n[i].size() == 0){
      domaine_null=true;
      break;
    }
  }
  if(all1 && sat){
    n.set_solution(true);
  }
  if(!sat || domaine_null){
    for(unsigned int i=0;i<n.nb_vars();i++){
      n[i].remove_all();
    }
  }

}    

