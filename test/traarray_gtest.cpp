// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 8, 2014
// License : GPL V2
//

#include <iostream>
#include <vector>

#include <traarray.h>
#include "gtest/gtest.h"

using namespace std;

namespace 
{ 
  TEST(BHeapTest, SimpleTest)
  { TrAArray T(10);
    vector<int> v;
    for(int i=0; i<10; ++i)
      v.push_back(i);
    EXPECT_EQ(0, T.Build(v.begin(), v.end()));
    EXPECT_EQ(0, T.Sum(0,0));
    EXPECT_EQ(1, T.Sum(0,1));
    EXPECT_EQ(15, T.Sum(0,5));
    EXPECT_EQ(45, T.Sum(0,9));
    EXPECT_EQ(26, T.Sum(5,8));
    EXPECT_EQ(44, T.Sum(2,9));
  }
  
  TEST(BHeapTest, ComplexTest)
  { TrAArray S(10);
    vector<int> v;
    for(int i=0; i<10; ++i)
      v.push_back(i);
    EXPECT_EQ(0, S.Build(v.begin(), v.end()));
    EXPECT_EQ(26, S.Sum(5,8));
    EXPECT_EQ(44, S.Sum(2,9));
    S.Set(0, 11);
    EXPECT_EQ(11, S.Sum(0));
    EXPECT_EQ(12, S.Sum(1));
    EXPECT_EQ(17, S.Sum(3));
    EXPECT_EQ(21, S.Sum(11,4));
  }
}


int main(int argc, char**argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
