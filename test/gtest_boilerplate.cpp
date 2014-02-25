#include <binary_heap.h>

#include "gtest/gtest.h"

namespace 
{ class FooTest : public ::testing::Test
  { FooTest(){}
    virtual ~FooTest(){}
    virtual void SetUp(){}
    virtual void TearDown(){}
  };


  TEST_F(FooTest, MethodBarDoesAbc)
  { const string input_filepath = "this/pack/my_input_file.dat";
    const string output_filepath = "this/pack/my_output_file.dat";
    Foo f;
    EXPECT_EQ(0, F.Bar(input_filepath, output_filepath));
  }

  TEST_F(FooTest, DoesXyz)
  {}
}
} //namespace


int main(int argc, char **argv)
{ ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
