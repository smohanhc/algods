#include <iostream>
#include "bit.h"

using namespace std;

int main()
{ 
  
  BITree B(5);
  vector<int> v;
  int count=5;

  for(int i=0; i<count; ++i)
  { v.push_back(i);
    cout << v[i] << " " ;
  }
  cout << endl;

  if(B.Build(v.begin(), v.end())==-1)
  { cout << "Error, Initialized size and vector size do not match." << endl;
    return 0;
  }

  for(int i=0; i<count; ++i)
    cout << "Sum upto "<< i << " is " << B.Sum(i) << endl;

  cout << "Sum  (0,4]  "<< " is " << B.Sum(0,4) << endl;
  B.Set(3, 5);
  cout << "Sum  (0,4]  "<< " is " << B.Sum(0,4) << endl;
  B.Set(5,3);
  cout << "Sum  (0,4]  "<< " is " << B.Sum(0,4) << endl;

  return 0; 
}
