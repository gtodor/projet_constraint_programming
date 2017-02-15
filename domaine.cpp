#include <iostream>
#include "domaine.hpp"

using namespace std;

domaine::domaine(){
  
}


domaine::domaine(const domaine& d): list_val(d.list_val){
  
}

domaine::~domaine(){

}


int& domaine::operator[](unsigned int index){
  cout<<"domaine::operator[](unsigned int index)"<<endl;
  if(index >= list_val.size()){
    throw std::invalid_argument("index out of bounds");
  }
  list<int>::iterator it = list_val.begin();
  std::advance(it,index);
  return *it;
}


int domaine::head(){
  return list_val.front();
}

domaine& domaine::operator=(domaine& other){
  if(this == &other) return *this;
  list_val.erase(list_val.begin(), list_val.end());
  for(list<int>::iterator it = other.begin(); it!=other.end(); ++it){
    list_val.push_back(*it);
  }
  return *this;
}

unsigned int domaine::size() const{
  return list_val.size();
}

void domaine::push_front(int val){
  list_val.push_front(val);
}

void domaine::push_back(int val){
  list_val.push_back(val);
}

list<int>::iterator domaine::begin(){
  return list_val.begin();
}

list<int>::iterator domaine::end(){
  return list_val.end();
}

void domaine::remove_all(){
  list_val.erase(list_val.begin(), list_val.end());
}

void domaine::remove(unsigned int index){
  cout<<"domaine::remove(unsigned int index)"<<endl;
  if(index >= list_val.size()){
    throw std::invalid_argument("index out of bounds");
  }
  list<int>::iterator it = list_val.begin();
  std::advance(it,index);
  list_val.erase(it);
}

void domaine::pop_front(){
  list_val.pop_front();
}

void domaine::print_domaine(){
  cout<<"{ ";
  if(!list_val.empty()){
    cout<<list_val.front();
    list_val.pop_front();
  }
  while(!list_val.empty()){
    cout<<" , "<<list_val.front();
    list_val.pop_front();
  }
  cout<<" }"<<endl;
}


    
