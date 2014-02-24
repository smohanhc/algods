#include <iostream>
#include <binaryheap.h>

using namespace std;

int main()
{ 
  //Test 1 : INT, Heapify, Delete all, ExtractXtrma, Insert
  vector<int> s;
  for(int i=0;i<5;++i)
    s.push_back(i);
  BinaryHeap<int> B(5);
  if(B.Heapify(s.begin(), s.end())<0)
  { cout << "Error, initialized size and given size of data input don't match." << endl; 
    return -1;
  }
  B.Delete(4); 
  B.Delete(3); 
  B.Delete(2); 
  B.Delete(1); 
  B.Delete(0); 
  cout << "Extrma " << B.FindXtrma() << endl;
  B.ExtractXtrma();
  B.Insert(1); 
  cout <<"Min value is : " << B.FindXtrma() << endl;
  s.clear();
  B.clear();


  //Test 2 : INT, Test a few Increase key, Decrease key 
  for(int i=0;i<=5;++i)
   s.push_back(i);
  if(B.Heapify(s.begin(), s.end())<0)
  { cout << "Error " << endl; 
    return -1;
  }
  B.IncreaseKey(5, 4);
  B.IncreaseKey(7, -4);
  B.IncreaseKey(8, 4);
  B.DecreaseKey(1, 12);
  B.DecreaseKey(2, -4);
  B.DecreaseKey(3, 4);
  B.Insert(1);
  B.Insert(2);
  B.Insert(4);
  B.Insert(1);
  cout <<"Min value is : " << B.FindXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  cout <<"Min value is : " << B.ExtractXtrma() << endl;
  B.clear();
  s.clear();

  //Test 3 : std::string
  /*vector<string> st;
  st.push_back("hello");
  st.push_back("aworld");
  st.push_back("you there");
  BinaryHeap<string> B1(3);
  B1.Heapify(st.begin(), st.end());
  cout << B1.ExtractXtrma() << endl;
  cout << B1.ExtractXtrma() << endl;
  cout << B1.ExtractXtrma() << endl;
  */
  
  //Test 4: float
  vector<float> ft;
  ft.push_back(1.660);
  ft.push_back(4.0);
  ft.push_back(2.33);
  ft.push_back(2.32);
  BinaryHeap<float> B2(4);
  B2.Heapify(ft.begin(), ft.end());
  cout << B2.ExtractXtrma() << endl;
  cout << B2.ExtractXtrma() << endl;
  cout << B2.ExtractXtrma() << endl;
  cout << B2.ExtractXtrma() << endl;
  
  
  return 0;

};

