// Copyright (c) 2014 Sumod K Mohan, All rights reserved.
// Date : Mar 12, 2014
// License : GPL V2


#include <disjoint_set.h>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// Checked till size of 100M.
namespace
{ //template<class T>
  class DSetTest : public ::testing::Test
  {
   public:
    Universe u1;
    DSetTest() { u1 = Universe((long)10);}
    virtual ~DSetTest() {}

   protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
  };

  //typedef ::testing::Types<int, unsigned int, long> MyTypes;
  //TYPED_TEST_CASE(BHeapTest, MyTypes);

  TEST_F(DSetTest, SimpleTest)
  { this->u1.UnionSet(1,2);
    this->u1.UnionSet(3,4);
    this->u1.UnionSet(1,3);
    EXPECT_EQ(4, this->u1.get_size(1));
  }

  /*TEST_F(DSetTest, ComplexTest)
  { EXPECT_EQ(1000, this->b1.FindXtrma());
    for (int i = 0; i < 10; ++i)
      this->b1.ExtractXtrma();
    EXPECT_EQ(981, this->b1.size());
  }*/
}  //  namespace

int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
