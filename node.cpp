#include <iostream>
#include "node.hpp"

using namespace std;


node::node(int nr_vars) : domaines(nr_vars,domaine(0)), solution(false){
  
}

node::node(const node& n) : domaines(n.domaines){
  cout<<"inside node copy constructor"<<endl;
  solution = n.solution;
}

node& node::operator=(node& other){
  cout<<"inside node::operator="<<endl;
  if(this == &other) return *this;
  domaines.erase(domaines.begin(), domaines.end());
  for(unsigned int i=0; i<other.nb_vars(); i++){
    domaines.push_back(other[i]);
  }
  return *this;
}

domaine& node::operator[](unsigned int index){
  //cout<<"inside node::operator[] "<<endl;
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
  unsigned int min=0;
  for(unsigned int i=0; i<nb_vars(); i++){
    if(domaines[i].size() < domaines[min].size()) min = i;
  }
  return min;
}

vector<domaine> node::get_domaines(){
  return domaines;
}
