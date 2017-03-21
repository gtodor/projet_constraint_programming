#ifndef domaine_hpp
#define domaine_hpp

#include <list>

/*
 *class defining the domain data structure
 */
class domaine{
private:
  std::list<int> list_val;
  
public:
  /*
   *param[in] size of the domain
   *the domain is initialized with 0 values
   */
  domaine();

  domaine(const domaine& d);
  ~domaine();
  
  /*
   *with this operator we can access values of list_val directly from domain variable
   *ex : domaine d(2); d[0] = 1; d[1] = 2;
   */
  int& operator[](unsigned int index);


  int head();

  
  std::list<int>::iterator begin();
  std::list<int>::iterator end();
  /*
   *assignement operator used to deep copy from other to this domain
   */
  domaine& operator=(domaine& other);
  /*
   *compare two domaine
   */
  bool operator==(domaine& other);

  /*
   *return size of list_val
   */
  unsigned int size() const;

  void push_front(int val);
  void push_back(int val);
  void pop_front();

  /*
   *removes the element at index index; size of domain decrease by 1
   */
  void remove(unsigned int index);

  /*
   *removes all elements from the domain; size of domain becomes 0
   */
  void remove_all();

  /*
   *print the domain
   */
  void print_domaine();

};

#endif //domaine_hpp
