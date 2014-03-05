// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Feb 19, 2014
// License : GPL V2
//

#ifndef INCLUDE_BINARYHEAP_H_
#define INCLUDE_BINARYHEAP_H_

#include <vector>
#include <iterator>
#include <cmath>

// Assume min heap
template <class T>
class BinaryHeap
{
 private:
  unsigned long heap_capacity_;
  std::vector<T> data_;
  // typedef typename std::vector<T>size_type heap_size_;
  void SiftUp(const unsigned long& node);
  void SiftDown(const unsigned long& node);

 public:
  BinaryHeap(const unsigned long& num_elements); //This only reserves space, size is still 0.
  BinaryHeap();
  ~BinaryHeap() {}

  // Misc Operations (using STL namimg).
  void clear();                      // clear the object for reuse.
  unsigned long size(){return(data_.size());}

  // Main operations allowed by the data structure.
  template <class I>
  int Heapify(I start, I end);
  const T FindXtrma();
  const T ExtractXtrma();
  void Insert(const T& data);   // Insert(key)
  void Delete(const unsigned long& element);     // Delete(element)
  void IncreaseKey(const unsigned long& element, const T& change);
  void DecreaseKey(const unsigned long& element, const T& change);
  /* void Merge(class &Heap); */
};

#endif  // INCLUDE_BINARYHEAP_H_
