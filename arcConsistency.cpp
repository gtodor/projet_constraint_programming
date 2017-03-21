#include "arcConsistency.hpp"
#include <vector>
#include <iostream>

using namespace std;

arcConsistency::arcConsistency(problem* p): prune(p){

}

arcConsistency::~arcConsistency(){
  
}

void arcConsistency::prunning(node& n){
  //c(xi,xj):constraint, Di:domain, Dj:domaine
  /*foreach(ai in Di){
    if(!HasSupport(c,ai,DJ)){
      remove ai frome Di  
    }
  }*/

  

}

bool arcConsistency::HasSupport(node& n ){
  for(unsigned int i=0; i<n.nb_vars(); i++){
    if(false && /* (ai,aj) e Rc*/){
      return true;
    }
  }
  return false;
}

void arcConsistency::AC1(node& n){
  bool modified;
  modified = false;
  while(!modified){
    for(/*c(xi,xj)e C*/){
      Ei = Di;
      Ej = DJ;
      prunning(n); // (c(xi,xj),Di,Dj)
      prunning(n); // (c(xj,xi),Dj,Di)

      if(Ei != Di){

      } else if(Ej != Dj) {

      }
      // else modified = modified;
    }
  }
}