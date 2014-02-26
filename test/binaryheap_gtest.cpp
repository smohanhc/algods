#include <binaryheap.h>
#include <vector>

#define pi 3.1415

#include "gtest/gtest.h"

using namespace std;

namespace 
{ 
   
 // Test 1: Simple int test.
 TEST(BinHeapTest, SimpleTest)
 { vector<int> data;
   for(int i=0; i<5; ++i)
     data.push_back(i);
 
   BinaryHeap<int> B(5);
   ASSERT_EQ(0, B.Heapify(data.begin(), data.end()));
 }

 // Test  2: BHeap int : 5
 TEST(BHeapTest, SimpleIntTest)
 { vector<int> data_;
   for(int i=0; i<5; ++i)
   data_.push_back(i);
   
   BinaryHeap<int> b1;
   b1.Heapify(data_.begin(), data_.end());
   EXPECT_EQ(0, b1.ExtractXtrma());
   EXPECT_EQ(1, b1.ExtractXtrma());	  
   EXPECT_EQ(2, b1.ExtractXtrma());	  
   EXPECT_EQ(3, b1.ExtractXtrma());	  
   EXPECT_EQ(4, b1.ExtractXtrma());	  
   b1.Insert(4);
   EXPECT_EQ(4, b1.FindXtrma());	  
   b1.IncreaseKey(0, 2);
   EXPECT_EQ(6, b1.FindXtrma());	  
   b1.DecreaseKey(0, 2);
   EXPECT_EQ(4, b1.FindXtrma());	  
 }

 // Test 3: BHeap int : 1000
 TEST(BHeapTest, LargeIntTest)
 { vector<int> cdata_;
   for(int i=0; i<1000; ++i)
     cdata_.push_back(i);
   
   BinaryHeap<int> b2;
   b2.Heapify(cdata_.begin(), cdata_.end());
   EXPECT_EQ(0, b2.FindXtrma());
   for(int i=0; i<10; ++i)
     b2.ExtractXtrma();
   EXPECT_EQ(10, b2.FindXtrma());
 } 
 
 // Test 4: BHeap Float : 1000
 TEST(BHeapTest, LargeFloatTest)
 { vector<float> fdata_;
   for(int i=0; i<1000; ++i)
     fdata_.push_back(i*pi);
   
   BinaryHeap<float> b3;
   b3.Heapify(fdata_.begin(), fdata_.end());
   EXPECT_EQ(0, b3.FindXtrma());
   for(int i=0; i<10; ++i)
     b3.ExtractXtrma();
   EXPECT_LT(31.410, b3.FindXtrma());
   EXPECT_GT(31.420, b3.FindXtrma());
 }
  
 // Test 5: BHeap long : 1000000
 /*
 TEST(BHeapTest, LargeLongTest)
 { 
   vector<long> ldata_;
   for(long i=0; i<1000000; ++i)
     ldata_.push_back(i);
   
   BinaryHeap<long> b4;
   b4.Heapify(ldata_.begin(), ldata_.end());
   EXPECT_EQ(0, b4.FindXtrma());
   for(int i=0; i<10; ++i)
     b4.ExtractXtrma();
   EXPECT_EQ(10, b4.FindXtrma());
   EXPECT_EQ(10, b4.FindXtrma());
 }*/

} //namespace


int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
