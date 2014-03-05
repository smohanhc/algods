// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Feb 27, 2014
// License : GPL V2


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
    BHeapTest() { b1 = BinaryHeap<T>(1000);}
    virtual ~BHeapTest() {}

   protected:
    vector<T> data_;
    virtual void SetUp()
    {
      unsigned long max_val = 2000;
      // if(typeid(T).name()=='long)
      // if(std::is_same<T,long>::value)
      // max_val=10000;
      for (T i = 1000; i < (T)max_val; ++i)
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
  { EXPECT_EQ(1000, this->b1.FindXtrma());
    EXPECT_EQ(1000, this->b1.size());
    this->b1.Insert(3000);
    EXPECT_EQ(1000, this->b1.FindXtrma());
    EXPECT_EQ(1001, this->b1.size());
    this->b1.Delete(0);
    EXPECT_EQ(1001, this->b1.FindXtrma());
    EXPECT_EQ(1000, this->b1.size());
    this->b1.DecreaseKey(999, 1000);
    EXPECT_EQ(999, this->b1.FindXtrma());
    EXPECT_EQ(1000, this->b1.size());
    this->b1.IncreaseKey(0,1000);
    EXPECT_EQ(1001, this->b1.FindXtrma());
    EXPECT_EQ(1000, this->b1.size());
  }

  TYPED_TEST(BHeapTest, ComplexTest)
  { EXPECT_EQ(1000, this->b1.FindXtrma());
    EXPECT_EQ(1000, this->b1.size());
    for (int i = 0; i < 10; ++i)
      this->b1.ExtractXtrma();
    EXPECT_EQ(1010, this->b1.FindXtrma());
    EXPECT_EQ(990, this->b1.size());
    for (int i = 0; i < 10; ++i)
      this->b1.ExtractXtrma();
    EXPECT_EQ(1020, this->b1.FindXtrma());
    EXPECT_EQ(980, this->b1.size());
    this->b1.Insert(3232);
    EXPECT_EQ(981, this->b1.size());
  }
}  //  namespace

int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
