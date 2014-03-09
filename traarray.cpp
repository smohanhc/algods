// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 8, 2014
// License : GPL V2
//

#include <traarray.h>


// Get the leftmost node of last layer, for given num_elements
// Only works for 32bits, pls change to 32bit int, as per your compiler.
unsigned int LeftMostNode(unsigned int x)
{ int sum=0;
  x = BITS - __builtin_clz(x);
  for(int i=0;i<x;++i)
   sum += 1 << i;
  return sum;
}

unsigned int TreeSize(unsigned int x)
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
bool PureLeftNode(unsigned int num)
{ unsigned int prev_bit=1, count=0;
  for(unsigned int i=1; i<=BITS; ++i)
  { unsigned int curr_bit = num&(1<<i-1); 	  //Isolate only the left most bit
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



TrAArray::TrAArray(const unsigned int num_elements)
{ if(num_elements==0)
    num_elements_ = 10;
  else
    num_elements_ = num_elements;  
}

template<class I>
int TrAArray::Build(I start, I end)
{ if(std::distance(start, end) != num_elements_)
    return -1;
  
  // Calculate the various parameters.
  tree_size_ = TreeSize(num_elements_);
  //BinCeil(num_elements_*log2(num_elements_))-1;
  leftmost_node_ = LeftMostNode(num_elements_);
  data_.resize(tree_size_, 0);
  // node_.reserve(num_elements_);

  int i=leftmost_node_;
  // Set the leaf nodes, 
  for(std::vector<int>::iterator j = start; j != end ; ++j, ++i)
  { data_[i]=(int)*j;
    node_[*j]=(unsigned int)i;
    //node_.insert(std::pair<int,unsigned int>(*j,(unsigned int)i)); 
  }
  
  // Now calculate the sum, up the tree
  for(int i=tree_size_-leftmost_node_-2; i>=0; --i)
  { data_[i]=data_[2*i+1]+data_[2*i+2];
  }
 
 return 0; 
}

int TrAArray::Sum(const int a, const int b)
{ int sum_a=0, sum_b=0;
  sum_a = Sum(a);
  sum_b = Sum(b);
  if(sum_a != -1 && sum_b != -1)
  { return (a+abs(sum_a-sum_b));
  }
  else 
    return -1;
}

int TrAArray::Sum(const int a)
{ 
  int loc, sum=0;
  
  if(node_.find(a)!=node_.end())
    loc = node_[a]; 
  else
    return -1;
  
  while(!PureLeftNode((unsigned int)loc))
  { if(loc%2==1) 
    { sum = sum + data_[loc];
      loc = (loc-1-2)/2;
    }
    else
    { loc = (loc-2)/2;
    } 
  }
  sum = sum+ data_[(unsigned)loc];
  return sum;
}

int TrAArray::Set(const int key, const int new_key)
{  
  if(node_.find(key)==node_.end())
    return -1;
  int loc = node_[key];
  int diff = new_key - key; 
  node_[new_key]=node_[key];
  while(loc !=0)
  { data_[loc] += diff;
    if(loc%2==0)
      loc = (loc-2)/2;
    else 
      loc = (loc-1)/2;
  }
return 0;
}

template int TrAArray::Build(std::vector<int>::iterator, std::vector<int>::iterator);
//template int TrAArray::Build(std::vector<long>::iterator, std::vector<long>::iterator);
//template int TrAArray::Build(std::vector<float>::iterator, std::vector<float>::iterator);
//template int TrAArray::Build(std::vector<double>::iterator, std::vector<double>::iterator);

