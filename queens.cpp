#include <iostream>
#include <vector>
#include "queens.hpp"

using namespace std;


queens::queens(int size): problem("queens"), size(size){
  for(int i=0; i<size; i++){
    domaine d(size);
    for(int j=0;j<size;j++) d[j] = j;
    domaines.push_back(d);
  }
}

queens::~queens(){
  
}

bool queens::check_constraints(){
  vector<int> partial;
  for(int  i = 0; i < size; i++){
    if(domaines[i].size() == 1){
      partial.push_back(domaines[i][0]);
    }else{
      partial.push_back(-1);
    }
  }
  if(partial.size() > 1){
    for(int i=0; i<partial.size()-1;i++){
      for(int j=i+1; j<partial.size(); j++){
	if(partial[i] == partial[j]) return false;
	else if((partial[j] - partial[i]) == (j-i)) return false;
      }
    }
  }
  return true;
}

void queens::define_domains(){
  

}

//TO REDO --- it should print the solution NOT the domains
void queens::print_solutions(){
  for(int i=0; i<size ; i++){
    domaines[i].print_domaine();
  }
}
