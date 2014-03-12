// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 8, 2014
// License : GPL V2
//

#include <traarray.h>
#include <iostream>

// Get the leftmost node of last layer, for given num_elements
// Only works for 32bits, pls change to 32bit int, as per your compiler.
unsigned long LeftMostNode(unsigned long x)
{ unsigned long sum=0;
  x = BITS - __builtin_clz(x);
  for(int i=0;i<(int)x;++i)
   sum += 1 << i;
  return sum;
}

unsigned long TreeSize(unsigned long x)
{ // Calculate the next power of two.
  x--;
  x = x | (x >> 1);
  x = x | (x >> 2);
  x = x | (x >> 4);
  x = x | (x >> 8);
  x = x | (x >> 16);
  x++;
  // Now calculate the total nodes till here, 
  // which is the same as LeftMostNode
  return(LeftMostNode(x));
};

// Left most nodes have a node number which is 1, 3, 7, 15, 
// i.e; All bits set
bool PureLeftNode(unsigned long num)
{ unsigned int prev_bit=1, count=0;
  for(unsigned int i=1; i<=BITS; ++i)
  { unsigned int curr_bit = num&(1<<(i-1)); 	  //Isolate only the left most bit
    curr_bit = curr_bit>>(i-1);                   // Propagate it out
    if(curr_bit ^ prev_bit)
    { ++count;
    }
    if(count>1)
      return false;
    prev_bit = curr_bit;
  }
    return true;
};


/*TrAArray::TrAArray(const unsigned long& num_elements)
{ 
  if(num_elements==0)
    num_elements_ = 10;
  else
    num_elements_ = num_elements;  
}*/

template<class T>
template<class I>
int TrAArray<T>::Build(I start, I end)
{ 
  // Calculate the various parameters.
  num_elements_ = std::distance(start, end);
  tree_size_ = TreeSize(num_elements_);
  leftmost_node_ = LeftMostNode(num_elements_);
  data_.resize(tree_size_, 0);
  /* node_.reserve(num_elements_); */

  // Set the leaf nodes, 
  unsigned long i=leftmost_node_;
  for(I j = start; j != end ; ++j, ++i)
  { data_[i]=(T)*j;
    node_[(*j)]=(unsigned long)i;
    //node_.insert(std::pair<int,unsigned int>(*j,(unsigned int)i)); 
  }
  
  // Now calculate the sum, up the tree
  i=tree_size_-leftmost_node_-2;
  do
  { data_[i]=data_[2*i+1]+data_[2*i+2];
    --i;
  }while(i>0);
 
 return 0; 
}

template <class T>
const T TrAArray<T>::Sum(const unsigned long& a, const unsigned long& b)
{ long sum_a=0, sum_b=0;
  sum_a = Sum(a);
  sum_b = Sum(b);
  if(sum_a != -1 && sum_b != -1)
  { return (data_[leftmost_node_+a]+abs(sum_a-sum_b));
  }
  else 
    return -1;
}

template <class T>
const T TrAArray<T>::Sum(const unsigned long& range_end)
{ 
  T sum=0;
  unsigned long end = leftmost_node_+range_end;

  //if(node_.find(a)!=node_.end())
  //  loc = node_[a]; 
  //else
  // return -1;
  
  while(!PureLeftNode((unsigned long)end))
  { if(end%2==1) 
    { sum = sum + data_[end];
      end = (end-1-2)/2;
    }
    else
    { end = (end-2)/2;
    } 
  }
  sum = sum+ data_[end];
  return sum;
}

template <class T>
int TrAArray<T>::Set(const unsigned long& elem, const T& new_key)
{  
  //if(node_.find(key)==node_.end())
  //  return -1;
  unsigned long element = leftmost_node_+elem;
  T key = data_[element];
  T diff = new_key - key; 
  std::cout<<"Data at set is " << node_[key]<< std::endl;
  node_[new_key]=node_[key];
  node_.erase(key);
  while(element !=0)
  { data_[element] += diff;
    if(element%2==0)
      element = (element-2)/2;
    else 
      element = (element-1)/2;
  }
return 0;
}

template <class T>
unsigned long TrAArray<T>::Find(const T& key)
{ typename std::unordered_map<T, unsigned long>::iterator j = node_.find(key);
  if(j != node_.end())
    { return j->second;
    }
  else 
   return -1;
}

template class TrAArray<int>;
template class TrAArray<unsigned int>;
template class TrAArray<long>;
// template class TrAArray<float>;
// template class TrAArray<char>;


template int TrAArray<int>::Build(std::vector<int>::iterator, std::vector<int>::iterator);
template int TrAArray<unsigned int>::Build(std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator);
template int TrAArray<long>::Build(std::vector<long>::iterator, std::vector<long>::iterator);
// template int TrAArray::Build(std::vector<float>::iterator, std::vector<float>::iterator);
// template int TrAArray::Build(std::vector<double>::iterator, std::vector<double>::iterator);

