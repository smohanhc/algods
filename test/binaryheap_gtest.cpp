#include <binaryheap.h>
#include <vector>
#include <type_traits>

#define pi 3.1415

#include "gtest/gtest.h"

using namespace std;

// Checked till size of 100M.
namespace 
{ template<class T>
  class BHeapTest : public ::testing::Test
  { 
    public:
    BinaryHeap<T> b1;
    BHeapTest() { b1 = BinaryHeap<T>(100000);}
    virtual ~BHeapTest(){}
    
    protected:
    vector<T> data_;
    virtual void SetUp()
    { 
      int max_val=100000;
      // if(typeid(T).name()=='long)
      // if(std::is_same<T,long>::value)
      // max_val=10000;	    
      for(T i=0; i<max_val; ++i)
        data_.push_back(i);
      b1.Heapify(data_.begin(), data_.end());
    }
    virtual void TearDown()
    { data_.clear();
    }
  };
 
  typedef ::testing::Types<int, unsigned int, long> MyTypes;
  TYPED_TEST_CASE(BHeapTest, MyTypes);
  
  TYPED_TEST(BHeapTest, SimpleTest)
  { EXPECT_EQ(0, this->b1.FindXtrma());
    EXPECT_EQ(100000, this->b1.get_size());
  }
} //namespace


int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
