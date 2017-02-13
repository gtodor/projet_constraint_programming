#include <iostream>
#include "domaine.hpp"

using namespace std;

domaine::domaine(int size): list_val(size,0){
  
}


domaine::domaine(const domaine& d): list_val(d.list_val){
  
}

domaine::~domaine(){

}

int& domaine::operator[](unsigned int index){
  if(index >= list_val.size()){
    throw std::invalid_argument("index out of bounds");
  }
  return list_val[index];
}

domaine& domaine::operator=(domaine& other){
  if(this == &other) return *this;
  this->remove_all();
  for(unsigned int i=0; i<other.size(); i++){
    list_val.push_back(other[i]);
  }
  return *this;
}

unsigned int domaine::size(){
  return list_val.size();
}

void domaine::remove_all(){
  list_val.erase(list_val.begin(), list_val.end());
}

void domaine::remove(unsigned int index){
  if(index >= list_val.size()){
    throw std::invalid_argument("index out of bounds");
  }
  list_val.erase(list_val.begin()+index);
}

void domaine::print_domaine(){
  cout<<"{ ";
  if(list_val.size() == 0){
    cout<<"}"<<endl;
    return;
  }
  for(unsigned int i=0;i<list_val.size() - 1;i++){
    cout<<list_val[i]<<" , ";
  }
  cout<<list_val[list_val.size()-1];
  cout<<" } "<<endl;
}


    
