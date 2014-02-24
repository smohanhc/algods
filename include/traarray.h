#ifndef BIT_H
#define BIT_H

#define BITS 32

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

unsigned int LeftMostNode(unsigned int x);
unsigned int TreeSize(unsigned int x);
bool PureLeftNode(unsigned int num);

class BITree
{ private:
    std::vector<int> data_;
    std::unordered_map<int,unsigned int> node_;
    unsigned int num_elements_;
    int leftmost_node_;
    int height_;
    unsigned int tree_size_;

  public:
    BITree(const unsigned int num_elements);
    ~BITree(){};
    template<class I>
    int Build(I start, I end);
    int Set(const int key, const int new_key);
    int Sum(const int a);
    int Sum(const int a, const int b);
    /*int Min(const int a, const int b);
    int Max(const int a, const int b);
    */
};


#endif
