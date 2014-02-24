#ifndef MST_DISJOINT_SET_H_
#define MST_DISJOINT_SET_H_
 
typedef struct
{ int rank;
  long int parent;
  long int size;
} Elt;

// QN :
// Why use Vector, it will change the worst case guarantees of find, union and make. Is this true ? Is there anyway I can make it more effective.
// But then you have to allocate and deallocate.
/* vector<elt> *elts_; */

class Universe 
{ 
  private : 
  Elt *elts_; 
  long int num_elements_; 
  
  public :
  Universe(long int elements);
 
  ~Universe();  
  void UnionSet(long int x, long int y);
  long int FindSet(long int x);  
  long int PrintGraph(char* filename);
  long int get_size(long int x) {return elts_[x].size;};
  long int get_num_elements(){return num_elements_; };
  long int get_parent(long int x){return elts_[x].parent;}
  long int get_rank(long int x) {return elts_[x].rank; };
};  

#endif //DISJOINT_SET_H_
