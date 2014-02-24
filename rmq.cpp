#include "include/rmq.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/// Various Preprocess

// Naive DP : M is O(n^2).
// Preprocess : O(n^2) and O(1) Query.
int RMQ::LookupTable()
{ 
  type_= 0;
  M_.resize(A_.size(), vector<int>(A_.size()));
  for(unsigned int i=0; i<M_.size(); ++i)
   M_[i][i]=i;
  
  for(unsigned int i=0; i<M_.size(); ++i)
  { for(unsigned int j=i+1; j<M_[i].size(); ++j)
    { if(A_[M_[i][j-1]]<A_[j])
        M_[i][j]=M_[i][j-1];
      else
        M_[i][j]=j;
    }
  }   
  return 0;  
}


// Squareroot Partitions : M is O(sqrt(n)).
// Preprocess : O(n) and O(sqrt(n)) Query.
int RMQ::SqrtPart()
{ 
  type_ = 1;
  int min_elem=0, j=1;
  M_.resize((int)ceil(sqrt(A_.size())), vector<int>(1,0));
  int sq_n=floor(sqrt(A_.size())); 
  
  for(unsigned int i=0; i<A_.size(); i++)
  { if(i>(j*sq_n))
    { M_[j-1][0]=min_elem;
      ++j;
      min_elem=i;
    }
    
    if(A_[i]<A_[min_elem])
      min_elem = i;
  } 
  
  M_[j-1][0]=min_elem;
  return 0;
}


/// Query and Update functions.
int RMQ::Query(int a, int b)
{ 
  if(type_==0)
   return M_[a][b];

  if(type_==1)
  { int a_bin, b_bin, min_elem, min_elem2;
    a_bin = a%((int)floor(sqrt(A_.size())));
    b_bin = b%((int)floor(sqrt(A_.size())));  
    min_elem = min(M_[a_bin][0], M_[b_bin][0]);
    min_elem2 = M_[min_element(M_.begin()+a_bin, M_.begin()+b_bin)]; 
    //    min(min_elem, 
    /*vector<int> min_vals = { M_[a_bin][0], 
                             min_element(M_.begin()+a_bin, M_.begin()+b_bin),
                             M_[b_bin][0]};
    */
    return min_elem; 
  }

  else
   return -1;
}

int RMQ::Print()
{ 
  cout << "Printing M " << endl;
  if(type_==0)
  { for(unsigned int i=0; i<M_.size(); ++i)
    { for(unsigned int j=0; j<M_[i].size(); ++j)
        cout << M_[i][j] << " ";
      cout << endl;
    }
    cout << endl;
  }
 
  if(type_==1)
  { for(unsigned int i=0; i<M_.size(); ++i)
     cout << M_[i][0] << " ";
  }   
  
  return 0;
}
