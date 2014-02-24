#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <iterator>
#include <math.h>

//Assume min heap
template <class T>
class BinaryHeap
{ 
  private:
   unsigned int heap_size_;
   std::vector<T> data_;
   //typedef typename std::vector<T>size_type heap_size_;
   void SiftUp(unsigned int node);
   void SiftDown(unsigned int node);

  public: 
   BinaryHeap(unsigned int num_elements);
   ~BinaryHeap(){};
   
   // Misc Operations (using STL namimg). 
   int count() { return heap_size_;};	//Get count of objects.
   void clear(); 			//clear the object for reuse.
   
   // Main operations allowed by the data structure.
   template <class I>
   int Heapify(I start, I end);
   const T FindXtrma(); 
   const T ExtractXtrma();			
   void Insert(const T& data); 		// Insert(key)
   void Delete(int element); 		// Delete(element)
   void IncreaseKey(int element, const T& change);
   void DecreaseKey(int element, const T& change);
   //void Merge(class &Heap);

};

#endif
