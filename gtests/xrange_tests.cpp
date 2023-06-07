#include <gtest/gtest.h>
#include "xrange.h"

TEST(XrangeIteratorTest, BasicTest) {
  xrange<int> xr(5);
  auto it = xr.begin();

  EXPECT_EQ(*it, 0);

  ++it;
  EXPECT_EQ(*it, 1);

  it++;
  EXPECT_EQ(*it, 2);

  ++it;
  EXPECT_EQ(*it, 3);

  ++it;
  EXPECT_EQ(*it, 4);

  ++it;
  EXPECT_TRUE(it == xr.end());
}

TEST(XrangeIteratorTest, NegativeStep) {
  xrange<int> xr(5, 0, -1);
  auto it = xr.begin();

  EXPECT_EQ(*it, 5);

  ++it;
  EXPECT_EQ(*it, 4);

  it++;
  EXPECT_EQ(*it, 3);

  ++it;
  EXPECT_EQ(*it, 2);

  ++it;
  EXPECT_EQ(*it, 1);

  ++it;
  EXPECT_TRUE(it == xr.end());
}

TEST(XrangeIteratorTest, StepGreaterThanOne) {
  xrange<int> xr(0, 10, 2);
  auto it = xr.begin();

  EXPECT_EQ(*it, 0);

  ++it;
  EXPECT_EQ(*it, 2);

  it++;
  EXPECT_EQ(*it, 4);

  ++it;
  EXPECT_EQ(*it, 6);

  ++it;
  EXPECT_EQ(*it, 8);

  ++it;
  EXPECT_TRUE(it == xr.end());
}

TEST(XrangeIteratorTest, StepLessThanOne) {
  xrange<float> xr(0.5, 1.5, 0.25);
  auto it = xr.begin();

  EXPECT_FLOAT_EQ(*it, 0.5);

  ++it;
  EXPECT_FLOAT_EQ(*it, 0.75);

  it++;
  EXPECT_FLOAT_EQ(*it, 1.0);

  ++it;
  EXPECT_FLOAT_EQ(*it, 1.25);

  ++it;
  EXPECT_TRUE(it == xr.end());
}

TEST(XrangeTest, RangeSize) {
  xrange<int> xr(10);
  EXPECT_EQ(std::distance(xr.begin(), xr.end()), 10);

  xrange<int> xr2(5, 15);
  EXPECT_EQ(std::distance(xr2.begin(), xr2.end()), 10);

  xrange<int> xr3(0, 10, 2);
  EXPECT_EQ(std::distance(xr3.begin(), xr3.end()), 5);
}

TEST(XrangeTest, RangeIteration) {
  std::vector<int> v{0, 1, 2, 3, 4};
  int i = 0;

  for (auto x : xrange<int>(5)) {
    EXPECT_EQ(x, v[i]);
    i++;
  }

  std::vector<float> v2{0.5, 0.75, 1.0, 1.25};
  int j = 0;

  for (auto x : xrange<float>(0.5, 1.5, 0.25)) {
    EXPECT_FLOAT_EQ(x, v2[j]);
    j++;
  }
}