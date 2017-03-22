#include <iostream>
#include <vector>
#include "queens.hpp"
#include <cmath>

using namespace std;


queens::queens(int size): problem("queens"), size(size){
  define_domains();
}

queens::~queens(){
  
}

bool queens::check_constraints(vector<domaine>& n){
  for(unsigned int i=0; i<n.size()-1;i++){
    for(unsigned int j=i+1; j<n.size(); j++){
      if(n[i].size() == 1 && n[j].size() == 1){
	if(n[i].head() == n[j].head()) return false;
	else if(abs(n[j].head() - n[i].head()) == abs(j-i) ) return false;
      }
    }
  }
  return true;
}

bool queens::check_constraints(int val1,int ind1, int val2, int ind2){
  //cout<<"checking constraints for "<<val1<<" in var "<<ind1<<" and "<<val2<<" in var "<<ind2<<endl;
  if(val1 == val2) return false;
  else if(abs(val1 - val2) == abs(ind1-ind2)) return false;
  return true;
}

void queens::define_domains(){
  for(int i=0; i<size; i++){
    domaine d;
    for(int j=0;j<size;j++) d.push_back(j); 
    domaines.push_back(d);
  }
}
