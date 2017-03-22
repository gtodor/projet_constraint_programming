#include <iostream>
#include "forward_checking.hpp"

using namespace std;


forward_checking::forward_checking(problem* p) : prune(p){

}

forward_checking::~forward_checking(){

}


void forward_checking::prunning(node& n){
  vector<domaine> d = n.get_domaines();
  bool sat = p->check_constraints(d);
  bool all1 = true;
  bool domaine_null = false;
  //cout<<"checking if node is ok"<<endl;
  //n.print_node();
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
    //cout<<endl<<"FOUND A SOLUTION"<<endl<<endl;
    n.set_solution(true);
  }
  if(!all1 && sat && !domaine_null){
    //cout<<"executing forward checking"<<endl;
    //execute the forward checking to prune the domains
    //n.print_node();
    for(unsigned int i=0; i<n.nb_vars(); i++){
      
      if(n[i].size() == 1){
	//check in the other domains if there are values not satisfying the constraints
	for(unsigned int j = 0; j<n.nb_vars(); j++){
	  if(i != j && n[j].size() > 1){
	    for(unsigned int k = 0; k<n[j].size(); k++){
	      bool psat = p->check_constraints(n[j][k],j,n[i].head(),i);
	      if(psat == false){
		//cout<<"removing value "<<n[j][k]<<" of domain "<<j<<endl;
		n[j].remove(k);
		k--;
	      }
	    }
	  }
	}
      }
    }
    //n.print_node();
    vector<domaine> dom = n.get_domaines();
    sat = p->check_constraints(dom);
    all1 = true;
    for(unsigned int i=0; i<n.nb_vars(); i++){
      if(n[i].size() != 1){
	all1=false;
	break;
      }
    }
    if(all1 && sat){
      //cout<<endl<<"FOUND A SOLUTION"<<endl<<endl;
      n.set_solution(true);
    }
    //cout<<"ending forward_checking"<<endl;
  }
  if(!sat || domaine_null){
    //cout<<"there is a null domain. Removin node content"<<endl;
    for(unsigned int i=0;i<n.nb_vars();i++){
      n[i].remove_all();
    }
  }
}
