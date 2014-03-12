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
  template<class T>
  class TraarrayTest : public ::testing::Test
  { public:
     TraarrayTest() {};
     ~TraarrayTest() {};

    protected:
     virtual void SetUp(){};
     virtual void TearDown(){};
  };
	
  typedef ::testing::Types<int, unsigned int, long> MyTypes;
  TYPED_TEST_CASE(TraarrayTest, MyTypes);
  
  TYPED_TEST(TraarrayTest, SimpleTest)
  { TrAArray<TypeParam> R;
    vector<TypeParam> v;
    for(int i=0; i<10; ++i)
      v.push_back(i);
    EXPECT_EQ(0, R.Build(v.begin(), v.end()));
    EXPECT_EQ(0, R.Sum(0));
    EXPECT_EQ(1, R.Sum(1));
    EXPECT_EQ(15, R.Sum(5));
    EXPECT_EQ(45, R.Sum(9));
    EXPECT_EQ(26, R.Sum(5,8));
    EXPECT_EQ(44, R.Sum(2,9));
  }
  
  TYPED_TEST(TraarrayTest, ComplexTest)
  { TrAArray<TypeParam> S;
    vector<TypeParam> v;
    for(int i=0; i<10; ++i)
      v.push_back(i);
    EXPECT_EQ(0, S.Build(v.begin(), v.end()));
    EXPECT_EQ(26, S.Sum(5,8));
    EXPECT_EQ(44, S.Sum(2,9));
    S.Set(0, 11);
    EXPECT_EQ(11, S.Sum(0,0));
    EXPECT_EQ(12, S.Sum(0,1));
    EXPECT_EQ(17, S.Sum(0,3));
    EXPECT_EQ(21, S.Sum(0,4));
  }
}  // namespace


int main(int argc, char**argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
