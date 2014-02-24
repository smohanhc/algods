#include <vector>

class RMQ
{ 
  private:
  std::vector<int> A_;
  std::vector<std::vector<int>> M_;
  std::vector<int> V_; 
  int type_;

  public:
  RMQ(std::vector<int> Abar) : A_(Abar) {};
  ~RMQ() {};
  
  //Various Preprocess implementations.  // Preprocess, QueryTime
  int LookupTable();                     // O(n^2), O(1)   
  int SqrtPart();                        // O(n), O(sqrt(n))
  int SparseTable();                     // O(nlogn), O(1)
  int SegmentTree();                     // O(n), O(logn)
  
  //Transformation functions. 
  int RMQ2LCA();
  int LCA2RMQ();
   
  //Query and update functions.
  int Query(int a, int b);
  int Update();
  int Print();
};
