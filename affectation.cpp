#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "affectation.hpp"

using namespace std;


affectation::affectation(int tasks, int machines):
  problem("affectation"),
  tasks(tasks),
  machines(machines)
{
  gen_affect_matrix();
  define_domains();
}


affectation::~affectation(){
  
}

void affectation::define_domains(){
  for(int i=0; i<tasks; i++){
    domaine d;
    for(int j=0; j<machines; j++){
      if(affect_matrix[i][j] == 1){
	d.push_back(j);
      }
    }
    domaines.push_back(d);
  }
}

bool affectation::check_constraints(vector<domaine>& n){
  for(unsigned int i = 0; i<n.size()-1; i++){
    for(unsigned int j = i+1; j<n.size(); j++){
      if(n[i].size()==1 && n[j].size()==1){
	if(n[i].head() == n[j].head()) return false;
      }
    }
  }
  return true;
}


bool affectation::check_constraints(int ai,int indai,int aj,int indaj){
  (void)indai;
  (void)indaj;
  if(ai == aj) return false;
  return true;
}

void affectation::gen_affect_matrix(){
  srand(time(NULL));
  affect_matrix = new int*[tasks];
  for(int i = 0; i < tasks; i++){
    affect_matrix[i] = new int[machines];
  }
  int i = 0;
  while(i < tasks){
    bool only0 = true;
    for(int j = 0; j<machines; j++){
      int nr = rand()%2;
      if(nr == 1) only0 = false;
      affect_matrix[i][j] = nr;
    }
    if(only0 == false){
      i++;
    }
  }
}


