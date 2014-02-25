#include <binaryheap.h>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

namespace 
{ BinaryHeap<int> b1(5);
  class BHeapTest : public ::testing::Test
  { 
    public:
    BHeapTest(){}
    virtual ~BHeapTest(){}
    
    protected:
    virtual void SetUp()
    { //BHeap int : 5
      vector<int> data_;
      for(int i=0; i<5; ++i)
        data_.push_back(i);
      b1.Heapify(data_.begin(), data_.end());

      //BHeap int : 1000
   /* for(int i=0; i<1000; ++i)
        data_.push_back(i);
      b2.Heapify(data_.begin(), data_.end());

      //BHeap Float : 1000
      vector<int> fdata_;
      fdata_.clear(); 
      for(int i=0; i<1000; ++i)
        fdata_.push_back(i*pi);
      b3.Heapify(fdata_.begin(), fdata_.end());
    
      // BHeap long : 1000000
      vector<int> ldata_;
      ldata_.clear(); 
      for(int i=0; i<1000000; ++i)
        ldata_.push_back(i*);
      b4.Heapify(ldata_.begin(), ldata_.end());
    */
    }
    //virtual void TearDown(){}
  
    //BinaryHeap<int> b1;
  /*BinaryHeap<int> b2(1000);
    BinaryHeap<float> b3(1000);
    BinaryHeap<long> b4(1000000);
  */
  };


  TEST_F(BHeapTest, SimpleTest)
  { BinaryHeap<int> B(5);
    vector<int> data;
    for(int i=0; i<5; ++i)
      data.push_back(i);
    ASSERT_EQ(0, B.Heapify(data.begin(), data.end()));
  }

  TEST_F(BHeapTest, SimpleIntTest)
  { ASSERT_EQ(0, b1.ExtractXtrma());
    ASSERT_EQ(1, b1.ExtractXtrma());	  
    ASSERT_EQ(2, b1.ExtractXtrma());	  
    ASSERT_EQ(3, b1.ExtractXtrma());	  
    ASSERT_EQ(4, b1.ExtractXtrma());	  
    b1.Insert(4);
    ASSERT_EQ(4, b1.FindXtrma());	  
    b1.IncreaseKey(1, 2);
    ASSERT_EQ(6, b1.FindXtrma());	  
    b1.DecreaseKey(1, 2);
    ASSERT_EQ(4, b1.FindXtrma());	  
  }

} //namespace


int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
