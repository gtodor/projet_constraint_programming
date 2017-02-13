#include <iostream>
#include <vector>
#include "queens.hpp"

using namespace std;


queens::queens(int size): problem("queens"), size(size){
  define_domains();
}

queens::~queens(){
  
}

/*this method is called by the prune algorithm to check constraintes for a specific node
 */
bool queens::check_constraints(vector<domaine>& n){
  for(unsigned int i=0; i<n.size()-1;i++){
    for(unsigned int j=i+1; j<n.size(); j++){
      if(n[i].size() == 1 && n[j].size() == 1){
	if(n[i][0] == n[j][0]) return false;
	else if((n[j][0] - n[i][0]) == (j-i) ) return false;
      }
    }
  }
  return true;
}

void queens::define_domains(){
  for(int i=0; i<size; i++){
    domaine d(size);
    for(int j=0;j<size;j++) d[j] = j;
    domaines.push_back(d);
  }
}

//TO REDO --- it should print the solution NOT the domains
void queens::print_solutions(){
  for(int i=0; i<size ; i++){
    domaines[i].print_domaine();
  }
}
