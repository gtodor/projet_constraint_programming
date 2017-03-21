#include "arcConsistency.hpp"
#include <vector>
#include <iostream>

using namespace std;

arcConsistency::arcConsistency(problem* p): prune(p){

}

arcConsistency::~arcConsistency(){
  
}

void arcConsistency::reviseAC(domaine& Di, domaine& Dj){
  //c(xi,xj):constraint, Di:domain, Dj:domaine
  for(int i =0; i<di.size(); ++i){
     if(!HasSupport(Di[i], i, DJ)){
      //remove ai from Di
      Di.remove(i);  
    }
  }
}

bool arcConsistency::HasSupport(int ai,int indai, domaine dj ){
  for(int i =0; i<dj.size(); ++i){
    if(p->check_constraints(ai, indai, dj[i], i)){
      return true;
    }
  }
  return false;
}

void arcConsistency::prunning(node& n){
  bool modified = false;
  domaine Ei, Ej;
  modified = false;
  while(!modified){
    modified = false;
    for(unsigned int i=0; i<n.size()-1;i++){
      for(unsigned int j=i+1; j<n.size(); j++){
        Ei = n[i];
        Ej = n[j];
        reviseAC(n[i], n[j]); // (c(xi,xj),Di,Dj)
        reviseAC(n[j], n[i]); // (c(xj,xi),Dj,Di)
        if(Ei != n[i]){
          modified = true;
        } else if(Ej != n[j]) {
          modified = true;
        }
      }// else modified = modified;
    }
  }
}