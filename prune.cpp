#include <iostream>
#include "prune.hpp"

using namespace std;

prune::prune(problem* p): p(p){

}

prune::~prune(){
  delete p;
}
