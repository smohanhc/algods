// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Feb 19, 2014
// License : GPL V2

#include <binaryheap.h>
#include <vector>
#include <algorithm>

template <class T>
BinaryHeap<T>::BinaryHeap(const unsigned long& num_elements)
{ heap_capacity_ = num_elements;
  data_.reserve(num_elements);
}


template <class T>
BinaryHeap<T>::BinaryHeap()
{ heap_capacity_ = 0;
}

template <class T>
void BinaryHeap<T>::SiftDown(const unsigned long& node)
{ unsigned long lchild = 2*node+1;
  unsigned long rchild = 2*node+2;

  bool rexists = rchild < this->size();
  bool lexists = lchild < this->size();
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
void BinaryHeap<T>::SiftUp(const unsigned long& node)
{ long parent = floor(node/2)-(node+1)%2;
  bool pexists = parent >= 0;
  if (pexists && data_[parent] > data_[node])
  { std::swap(data_[parent], data_[node]);
    SiftUp(parent);
  }
}

template <class T>
template <class I>
int BinaryHeap<T>::Heapify(I start, I end)
{ unsigned long d = std::distance(start, end);
  if (this->size() != 0)
    this->clear();
  if (heap_capacity_ == 0 || d != heap_capacity_)
    heap_capacity_ = d;
  for (I i = start; i != end; ++i)
    data_.push_back(*i);
  for (unsigned long i = heap_capacity_-1; i <= heap_capacity_; --i)
  { SiftDown(i);
  }
  return 0;
}

template <class T>
const T BinaryHeap<T>::FindXtrma()
{ if (this->size() <= 0)
    return ((T)(0));
  return data_.front();
  // return this->data_[0];
}

template <class T>
const T BinaryHeap<T>::ExtractXtrma()
{ if (this->size() <= 0)
    return ((T)(0));
  T max_value = data_.front();
  std::swap(data_.front(), data_.back());
  data_.pop_back();
  --heap_capacity_;
  SiftDown(0);
  return max_value;
}

template <class T>
void BinaryHeap<T>::Insert(const T& new_node)
{ data_.push_back(new_node);
  SiftUp(this->size()-1);
  ++heap_capacity_;
}

template <class T>
void BinaryHeap<T>::Delete(const unsigned long& element)
{ if (element >= this->size())
    return;
  std::swap(data_[element], data_.back());
  data_.pop_back();
  --heap_capacity_;
  SiftUp(element);
  SiftDown(element);
}

template <class T>
void BinaryHeap<T>::IncreaseKey(const unsigned long& element, const T& change)
{ data_[element] = data_[element]+change;
  SiftDown(element);
}

template <class T>
void BinaryHeap<T>::DecreaseKey(const unsigned long& element, const T& change)
{ data_[element] = data_[element]-change;
  SiftUp(element);
}

template <class T>
void BinaryHeap<T>::clear()
{ if (this->size()  > 0)
    data_.clear();
}

// void Merge(class &heap)
// {
// };
//
//

template class BinaryHeap<int>;
template class BinaryHeap<float>;
template class BinaryHeap<unsigned int>;
template class BinaryHeap<long>;
// template class BinaryHeap<std::string>;

template int BinaryHeap<int>::Heapify(std::vector<int>::iterator, std::vector<int>::iterator);
template int BinaryHeap<float>::Heapify(std::vector<float>::iterator, std::vector<float>::iterator);
template int BinaryHeap<unsigned int>::Heapify(std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator);
template int BinaryHeap<long>::Heapify(std::vector<long>::iterator, std::vector<long>::iterator);
// template int BinaryHeap<std::string>::Heapify(std::vector<std::string>::iterator, std::vector<std::string>::iterator);
