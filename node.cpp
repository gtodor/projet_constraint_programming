#include <iostream>
#include "node.hpp"

using namespace std;


node::node(int nr_vars) : domaines(nr_vars,domaine(0)), solution(false){
  
}

node::node(const node& n) : domaines(n.domaines){
  solution = n.solution;
}

node& node::operator=(node& other){
  if(this == &other) return *this;
  domaines.erase(domaines.begin(), domaines.end());
  for(unsigned int i=0; i<other.nb_vars(); i++){
    domaines.push_back(other[i]);
  }
  return *this;
}

domaine& node::operator[](unsigned int index){
  if(index >= domaines.size()){
    throw std::invalid_argument("index out of bounds");
  }
  return domaines[index];
}

unsigned int node::nb_vars(){
  return domaines.size();
}

void node::print_node(){
  cout<<"NODE :"<<endl;
  for(unsigned int i = 0; i<domaines.size(); i++){
    cout<<" D"<<i<<" = ";
    (*this)[i].print_domaine();
  }
}

bool node::is_empty(){
  unsigned int c=0;
  for(unsigned int i=0; i<nb_vars();i++){
    if(domaines[i].size() == 0) c++;
  }
  if(c == nb_vars()){
    return true;
  }else{
    return false;
  }
}

bool node::is_solution(){
  return solution;
}

void node::set_solution(bool var){
  solution = var;
}

unsigned int node::smallest_domaine(){
  unsigned int min;
  bool found = false;
  for(unsigned int j=0;j<nb_vars(); j++){
    if(domaines[j].size() > 1){
      min = j;
      found = true;
      break;
    }
  }
  if(!found){
    return -2;
  }
  for(unsigned int i=0; i<nb_vars(); i++){
    if(domaines[i].size() > 1 && domaines[i].size() < domaines[min].size()) min = i;
  }
  return min;
}

vector<domaine> node::get_domaines(){
  return domaines;
}
