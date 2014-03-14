// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 12, 2014
// License : GPL V2
// This implementation is heavily influenced by Pedro Felzenswalb's Disjoint Set
// implementation, which can be found at http://cs.brown.edu/~pff/segment/

#ifndef INCLUDE_DISJOINT_SET_H_
#define INCLUDE_DISJOINT_SET_H_
 
typedef struct
{ int rank;
  long int parent;
  long int size;
} Elt;

class Universe 
{ 
 private : 
  Elt *elts_; 
  long int num_elements_; 
  
 public :
  Universe() {}
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

#endif // INCLUDE_DISJOINT_SET_H_
