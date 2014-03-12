// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 8, 2014
// License : GPL V2
// An implementation of Tree Atop an Array, with Build, Sum and Set operations.

#ifndef INCLUDE_TRAARRAY_H_
#define INCLUDE_TRAARRAY_H_

#define BITS 32

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

// Given array size, find left most node of the last layer of the tree.
unsigned long LeftMostNode(unsigned long x);
// Given array size, return size of smallest tree that fits the array.
unsigned long TreeSize(unsigned long x);
// Check if given node is pure left node of a layer.
bool PureLeftNode(unsigned long num);

template <class T>
class TrAArray
{ private:
    std::vector<T> data_;               // Tree atop array represented as an array. 
    std::unordered_map<T, unsigned long> node_;  // Augmented for efficient find. 
    unsigned long height_;		// Height of tree.
    unsigned long leftmost_node_;	// Index to leftmost node of last layer.
    unsigned long tree_size_;		// Size of the tree.
    unsigned long num_elements_;	// Number of elements in array.
    // unsigned long capacity_;		// Capacity of 
   
    
  public:
    TrAArray(){}; 					// Constructor.
    ~TrAArray(){};
    // TrAArray(const unsigned long& num_elements); 	// Reserve num_elements.
    
    template<class I>
    int Build(const I start, const I end);	// Returns -1 if size != num_elements.
    unsigned long Size(){return num_elements_;};   // Returns number of elements stored.
    unsigned long Find(const T& key);
    int Set(const unsigned long& element, const T& new_key);
    const T Sum(const unsigned long& end);
    const T Sum(const unsigned long& start, const unsigned long& end);
    
    // TODO
    /*
     * int Min(const int a, const int b);
       int Max(const int a, const int b);
    */
};


#endif // INCLUDE_TRAARRAY_H_
