#include <interval_tree.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{ 
  vector<intrvl> v;
  /*v.push_back(intrvl(1,3,0));
  v.push_back(intrvl(2,3,0));
  v.push_back(intrvl(4,6,0));
  v.push_back(intrvl(7,9,0));
  v.push_back(intrvl(7,8,0));

  Itree itree(5);
  itree.Build(v.begin(), v.end());
  cout << "Number of intervals overlapping the point " << argv[1] << 
	  " is " << itree.CountQuery(atoi(argv[1]), 0) << endl;
  itree.Insert(0, intrvl(1,4,0));
  cout << "Number of intervals overlapping the point " << argv[2] << 
	  " is " << itree.CountQuery(atoi(argv[2]), 0) << endl;
  itree.Delete(0, intrvl(1,4,0));
  */
 
  /*v.clear();
  v.push_back(intrvl(1,5,0));
  v.push_back(intrvl(2,3,0));
  v.push_back(intrvl(3,8,0));
  v.push_back(intrvl(4,6,0));
  v.push_back(intrvl(9,10,0));
  
  v.push_back(intrvl(13,23,0));
  v.push_back(intrvl(14,18,0));
  v.push_back(intrvl(16,19,0));
  v.push_back(intrvl(20,23,0));
  v.push_back(intrvl(21,22,0));

  v.push_back(intrvl(7,15,0));
  v.push_back(intrvl(11,12,0));
  v.push_back(intrvl(11,17,0));
  
  Itree itree_2(13);
  itree_2.Build(v.begin(), v.end());
  cout << "Number of intervals overlapping the point " << argv[1] <<" is " << itree_2.CountQuery(atoi(argv[1]), 0) << endl;
  */
 
  for(int i=0; i<20000; ++i)
    v.push_back(intrvl(i, i+rand()%10, 0));
  Itree itree_2(20000);
  itree_2.Build(v.begin(), v.end());
  cout << "Number of intervals overlapping the point is " << itree_2.CountQuery(100, 0) << endl;
  
  int num;
  for(int i=0; i<81; ++i)
  { 
    while(i!=num)
     num = i+rand()%100;
    itree_2.Insert(0, intrvl(i, num, 0));
    itree_2.Delete(0, intrvl(i, num, 0));
    //itree_2.Insert(0, intrvl(i, num+1, 0));
    //itree_2.Delete(0, intrvl(i, num+1, 0));
    //itree_2.Insert(0, intrvl(i, num+2, 0));
    //itree_2.Delete(0, intrvl(i, num+2, 0));
  } 
  return 0;
}
