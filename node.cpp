#include <iostream>
#include "node.hpp"

using namespace std;


node::node(int nr_vars) : domaines(nr_vars,domaine(0)){
  
}

node::node(const node& n) : domaines(n.domaines){
  cout<<"inside node copy constructor"<<endl;
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
