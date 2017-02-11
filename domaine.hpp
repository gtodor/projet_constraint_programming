#ifndef domaine_hpp
#define domaine_hpp

#include <vector>

class domaine{
private:
  std::vector<int> list_val;

public:
  domaine(int size);
  domaine(const domaine& d);
  ~domaine();

  int& operator[](unsigned int index); //array like behaviour
  domaine& operator=(domaine& other);
  unsigned int size();
  void remove(unsigned int index);
  void remove_all();
  void print_domaine();

};

#endif //domaine_hpp
