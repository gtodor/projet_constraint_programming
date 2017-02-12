#include <iostream>
#include <vector>
#include <string>
#include "problem.hpp"


using namespace std;


problem::problem(string name): name(name){

}

problem::~problem(){

}

vector<domaine> problem::get_domaines(){
  return domaines;
}

unsigned int problem::nb_vars(){
  return domaines.size();
}


