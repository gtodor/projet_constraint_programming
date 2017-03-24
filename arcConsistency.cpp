#include "arcConsistency.hpp"
#include <vector>
#include <iostream>

using namespace std;

arcConsistency::arcConsistency(problem* p): prune(p){

}

arcConsistency::~arcConsistency(){
  
}

void arcConsistency::reviseAC(domaine& Di,int indi, domaine& Dj, int indj){
  //c(xi,xj):constraint, Di:domain, Dj:domaine
  for(unsigned int i =0; i<Di.size(); ++i){
    if(!HasSupport(Di[i], indi, Dj, indj)){
      //remove ai from Di
      Di.remove(i);  
    }
  }
}

bool arcConsistency::HasSupport(int ai,int indai, domaine dj, int indj){
  for(unsigned int i =0; i<dj.size(); ++i){
    if(p->check_constraints(ai, indai, dj[i], indj)){
      //cout<<"var"<<indai<<"= "<<ai<<" and var"<<indj<<"= "<<dj[i]<<" satisfy the constraints"<<endl;
      return true;
    }
  }
  return false;
}

void arcConsistency::prunning(node& n){
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
    bool modified = true;
    domaine Ei, Ej;
    //modified = false;
    while(modified == true){
      modified = false;
      for(unsigned int i=0; i<n.nb_vars()-1;i++){
        for(unsigned int j=i+1; j<n.nb_vars(); j++){
          Ei = n[i];
          Ej = n[j];
	  //cout<<"checking domains "<<i<<" and "<<j<<endl;
          reviseAC(n[i], i, n[j], j); // (c(xi,xj),Di,Dj)
	  //cout<<"checking domains "<<j<<" and "<<i<<endl;
          reviseAC(n[j], j, n[i], i); // (c(xj,xi),Dj,Di)
          if(!(Ei == n[i] && Ej == n[j])){
            modified = true;
          }
        }// else modified = modified;
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
