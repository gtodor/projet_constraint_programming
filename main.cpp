#include <iostream>
#include <string>
#include <vector>

#include "problem.hpp"
#include "queens.hpp"
#include "affectation.hpp"
#include "solver.hpp"
#include "forward_checking.hpp"
#include "arcConsistency.hpp"

using namespace std;

int main(int argc, char** argv){

  if(argc != 2){
    cout<<"usage: 'solver queens' or 'solver affectation'"<<endl;
    return 1;
  }
  string type = argv[1];
  if(type != "queens" && type != "affectation"){
    cout<<"usage: 'solver queens' or 'solver affectation'"<<endl;
    return 1;
  }
  if(type == "queens"){
    int n;
    cout<<"size of board: n=";
    cin>>n;
    
    problem* p = new queens(n);
    string input;
    cout<<"Choose a prune algorithm (backtracking/forward_checking/arc_consistency) : ";
    cin>>input;
    while(input != "backtracking" && input !="forward_checking" && input != "arc_consistency"){
      cout<<"invalid input. Retry!"<<endl;
      cout<<"Choose a prune algorithm (backtracking/forward_checking/arc_consistency) : ";
      cin>>input;
    }
    solver* s = NULL;
    if(input == "backtracking"){
      s = new solver(p); // default prune algorithm -- backtracking
    }else if(input == "forward_checking"){
      s = new solver(p,new forward_checking(p)); // prune algorithm fwd chk
    }else{
      s = new solver(p, new arcConsistency(p));
    }
    s->solve();
    s->show_solutions();
  }else{
    int tasks, machines;
    cout<<"enter number of tasks = ";
    cin>>tasks;
    cout<<"enter number of machines = ";
    cin>>machines;
    bool proceed = false;
    problem* p = NULL;
    while(!proceed){
      p = new affectation(tasks,machines);
      p->print_problem();
      string resp;
      cout<<"type OK to solve this problem or AGAIN to choose other initialization : ";
      cin>>resp;
      while(resp != "OK" && resp != "AGAIN"){
	cout<<"input not valid retry"<<endl;
	cout<<"type OK to solve this problem or AGAIN to choose other initialization : ";
	cin>>resp;
      }
      if(resp == "OK"){
	proceed = true;
      }
    }
    string input;
    cout<<"Choose a prune algorithm (backtracking/forward_checking/arc_consistency) : ";
    cin>>input;
    while(input != "backtracking" && input !="forward_checking" && input != "arc_consistency"){
      cout<<"invalid input. Retry!"<<endl;
      cout<<"Choose a prune algorithm (backtracking/forward_checking/arc_consistency) : ";
      cin>>input;
    }
    solver* s = NULL;
    if(input == "backtracking"){
      s = new solver(p); // default prune algorithm -- backtracking
    }else if(input == "forward_checking"){
      s = new solver(p,new forward_checking(p)); // prune algorithm fwd chk
    }else{
      s = new solver(p, new arcConsistency(p));
    }
    s->solve();
    s->show_solutions();
  }

  return 0;
}
