#include <binaryheap.h>
#include <vector>

#define pi 3.1415

#include "gtest/gtest.h"

using namespace std;

namespace 
{ //BinaryHeap<int> b1(5);
 class BHeapTest : public ::testing::Test
 { 
   public:
   BHeapTest()
   { b1 = BinaryHeap<int>(5);
     b2 = BinaryHeap<int>(1000);
     b3 = BinaryHeap<float>(1000);
     //b4 = BinaryHeap<long>(1000);
   }
   virtual ~BHeapTest(){}
   
   protected:
   vector<int> data_;
   vector<int> cdata_;
   vector<float> fdata_;
   vector<long> ldata_;
   BinaryHeap<int> b1;
   BinaryHeap<int> b2;
   BinaryHeap<float> b3;
   //BinaryHeap<long> b4;
   
   virtual void SetUp()
   { // BHeap int : 5
     for(int i=0; i<5; ++i)
       data_.push_back(i);
     b1.Heapify(data_.begin(), data_.end());

     // BHeap int : 1000
      for(int i=0; i<1000; ++i)
       cdata_.push_back(i);
     b2.Heapify(cdata_.begin(), cdata_.end());

     //BHeap Float : 1000
     vector<float> fdata_;
     fdata_.clear(); 
     for(int i=0; i<1000; ++i)
       fdata_.push_back(i*pi);
     b3.Heapify(fdata_.begin(), fdata_.end());
   
     // BHeap long : 1000000
     /*vector<long> ldata_;
     ldata_.clear(); 
     for(long i=0; i<1000000; ++i)
       ldata_.push_back(i);
     b4.Heapify(ldata_.begin(), ldata_.end());*/
   }
   
   virtual void TearDown()
   { data_.clear();
     cdata_.clear();
     fdata_.clear();
     ldata_.clear();
   }
 };

 TEST(BinHeapTest, SimpleTest)
 { BinaryHeap<int> B(5);
   vector<int> data;
   for(int i=0; i<5; ++i)
     data.push_back(i);
   ASSERT_EQ(0, B.Heapify(data.begin(), data.end()));
 }


 TEST_F(BHeapTest, SimpleIntTest)
 { EXPECT_EQ(0, b1.ExtractXtrma());
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

 TEST_F(BHeapTest, LargeIntTest)
 { EXPECT_EQ(0, b2.FindXtrma());
   for(int i=0; i<10; ++i)
     b2.ExtractXtrma();
   EXPECT_EQ(10, b2.FindXtrma());
 } 
 
 TEST_F(BHeapTest, LargeFloatTest)
 { EXPECT_EQ(0, b3.FindXtrma());
   for(int i=0; i<10; ++i)
     b3.ExtractXtrma();
   EXPECT_LT(31.410, b3.FindXtrma());
   EXPECT_GT(31.420, b3.FindXtrma());
 }
  
 /*TEST_F(BHeapTest, LargeLongTest)
 { EXPECT_EQ(0, b4.FindXtrma());
   for(int i=0; i<10; ++i)
     b3.ExtractXtrma();
   EXPECT_EQ(10, b4.FindXtrma());
   EXPECT_EQ(10, b4.FindXtrma());
 }*/

} //namespace


int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
