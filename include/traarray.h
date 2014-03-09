// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 8, 2014
// License : GPL V2
//

#ifndef INCLUDE_TRAARRAY_H_
#define INCLUDE_TRAARRAY_H_

#define BITS 32

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

unsigned int LeftMostNode(unsigned int x);
unsigned int TreeSize(unsigned int x);
bool PureLeftNode(unsigned int num);

class TrAArray
{ private:
    std::vector<int> data_;
    std::unordered_map<int,unsigned int> node_;
    unsigned int num_elements_;
    int leftmost_node_;
    int height_;
    unsigned int tree_size_;

  public:
    TrAArray(const unsigned int num_elements);
    ~TrAArray(){};
    template<class I>
    int Build(I start, I end);
    int Set(const int key, const int new_key);
    int Sum(const int start);
    int Sum(const int start, const int end);
    /*int Min(const int a, const int b);
    int Max(const int a, const int b);
    */
};


#endif // INCLUDE_TRAARRAY_H_
