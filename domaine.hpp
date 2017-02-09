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

  const int& operator[](int index) const; //array like behaviour
  int get_size();
  void set_val(int index);
  void set_all_val(std::vector<int> v);//maybe not necessarry

};

#endif //domaine_hpp
