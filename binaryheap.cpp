// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Feb 19, 2014
// License : GPL V2

#include <binaryheap.h>
#include <vector>
#include <algorithm>

template <class T>
BinaryHeap<T>::BinaryHeap(unsigned int num_elements)
{ heap_size_ = num_elements;
  data_.reserve(num_elements);
}

template <class T>
void BinaryHeap<T>::SiftDown(unsigned int node)
{ unsigned int lchild = 2*node+1;
  unsigned int rchild = 2*node+2;

  bool rexists = rchild < heap_size_;
  bool lexists = lchild < heap_size_;
  if (!lexists && !rexists) return;
  bool left_small;
  if (rexists && data_[lchild] > data_[rchild])
    left_small = false;
  else
    left_small = true;

  if (data_[lchild] < data_[node] && left_small)
  { std::swap(data_[node], data_[lchild]);
    SiftDown(lchild);
  }
  else if (data_[rchild] < data_[node] && rexists && !left_small)
  { std::swap(data_[node], data_[rchild]);
    SiftDown(rchild);
  }
}

template <class T>
void BinaryHeap<T>::SiftUp(unsigned int node)
{ int parent = floor(node/2)-(node+1)%2;
  bool pexists = parent >= 0;
  if (pexists && data_[parent] > data_[node])
  { std::swap(data_[parent], data_[node]);
    SiftUp(parent);
  }
}

template <class T>
template <class I>
int BinaryHeap<T>::Heapify(I start, I end)
{ int d = std::distance(start, end);
  if (heap_size_ == 0)
    heap_size_ = d;
  if (d != heap_size_)
    return -1;
  for (I i = start; i != end; ++i)
    data_.push_back(*i);
  for (unsigned int i = heap_size_-1; i <= heap_size_; --i)
  { SiftDown(i);
  }
  return 0;
}

template <class T>
const T BinaryHeap<T>::FindXtrma()
{ if (heap_size_ <= 0)
    return ((T)(0));
  return data_.front();
  //return this->data_[0];
}

template <class T>
const T BinaryHeap<T>::ExtractXtrma()
{ if (heap_size_ <= 0)
    return ((T)(0));
  T max_value = data_.front();
  std::swap(data_.front(), data_.back());
  data_.pop_back();
  --heap_size_;
  SiftDown(0);
  return max_value;
}

template <class T>
void BinaryHeap<T>::Insert(const T& new_node)
{ data_.push_back(new_node);
  SiftUp(data_.size()-1);
  ++heap_size_;
}

template <class T>
void BinaryHeap<T>::Delete(int element)
{ if (element >= heap_size_)
    return;
  std::swap(data_[element], data_.back());
  data_.pop_back();
  --heap_size_;
  SiftUp(element);
  SiftDown(element);
}

template <class T>
void BinaryHeap<T>::IncreaseKey(int element, const T& change)
{ data_[element] = data_[element]+change;
  SiftDown(element);
}

template <class T>
void BinaryHeap<T>::DecreaseKey(int element, const T& change)
{ data_[element] = data_[element]-change;
  SiftUp(element);
}

template <class T>
void BinaryHeap<T>::clear()
{ if (heap_size_ > 0)
    Delete(heap_size_-1);
}

//void Merge(class &heap)
//{
//};
//
//

template class BinaryHeap<int>;
template class BinaryHeap<float>;
//template class BinaryHeap<std::string>;

template int BinaryHeap<int>::Heapify(std::vector<int>::iterator, std::vector<int>::iterator);
template int BinaryHeap<float>::Heapify(std::vector<float>::iterator, std::vector<float>::iterator);
//template int BinaryHeap<std::string>::Heapify(std::vector<std::string>::iterator, std::vector<std::string>::iterator);
