#include <vector>
#include <string>
#include <iostream>
#include "problem.hpp"

using namespace std;


problem::problem(string name): name(name){

}

problem::~problem(){

}

vector<domaine>& problem::get_domaines(){
  return domaines;
}

unsigned int problem::nb_vars(){
  return domaines.size();
}

void problem::print_problem(){
  for(unsigned int i = 0; i<domaines.size(); i++){
    cout<<"D["<<i<<"] = ";
    domaines[i].print_domaine();
  }
}
