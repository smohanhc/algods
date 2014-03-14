#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

#include <set>
#include <queue>
#include <vector>
#include <algorithm>

struct intrvl
{ int a;
  int b;
  int v;
  intrvl(int a, int b, int v): a(a), b(b), v(v){} 
  inline bool operator < (const intrvl &next) const
  { return ( a < next.a);
  }
  inline bool operator > (const intrvl &next) const
  { return ( a > next.a);
  }
};

struct node
{ 
  int left;
  int right;
  int parent;
  int index;
  int counter;
  int median;
  int subtree_size;
  std::multiset<intrvl> ldata;
  std::set<int> rdata;
  node(int index, int parent) : left(-1), right(-1), parent(parent), index(index), counter(0), median(0), subtree_size(0){}
};

// Note : Please do not use for more than 1M intervals for 4GB of RAM.
// The recursive calls could cause heap overflow.
// Possibly there could be stackoverflow even before :).
class Itree
{ 
  private:
   int num_elements_;
   std::vector<node> data_;
   std::vector<intrvl> pending_intrvls_;
   //std::queue<int> build_q_;
   //std::vector<intrvl> curr_intrvls_;

   void BuildItree(int node, std::vector<intrvl> intrvls); 
   int Balance(int node);  
   int Median(std::vector<intrvl> intrvls);
   int SwapOutNode(int del_node, int keep_node);

  public:
   // Constructors etc. 
   Itree(int num_elem);
   ~Itree(){};


   // Main operations of data structure.
   template<class IntrvlIter>
   void Build(const IntrvlIter start, const IntrvlIter end);
   
   // Count the number of intervals overlapping this point, node will default to 0.
   int CountQuery(int number, int node);
   int Insert(int node, intrvl interval);
   int Delete(int node, intrvl interval);
   
   // Yet to be implemented.
   //int CountQuery(int, int);
   //int EnumerateQuery(int);
   //int EnumerateQuery(int, int);
};


#endif
