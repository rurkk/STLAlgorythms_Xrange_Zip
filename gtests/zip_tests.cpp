#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include "zip.h"

TEST(ZipIteratorTest, BasicTest1) {
  std::vector<int> v1{1, 2, 3};
  std::list<std::string> l1{"a", "b", "c"};

  auto it1 = zip_iterator<std::vector<int>, std::list<std::string>>(v1.begin(), l1.begin());

  std::pair<int, std::string> p1(1, "a");
  EXPECT_EQ(*it1, p1);

  it1++;
  std::pair<int, std::string> p2(2, "b");
  EXPECT_EQ(*it1, p2);

  it1++;
  std::pair<int, std::string> p3(3, "c");
  EXPECT_EQ(*it1, p3);

  it1++;
  auto it2 = zip_iterator<std::vector<int>, std::list<std::string>>(v1.end(), l1.end());
  EXPECT_TRUE(it1 == it2);
}

TEST(ZipTest, BasicTest2) {
  std::vector<int> v1{1, 2, 3};
  std::vector<double> v2{1.1, 2.2, 3.3};

  auto z = zip<std::vector<int>, std::vector<double>>(v1, v2);

  EXPECT_EQ((*(z.begin())).first, 1);
  EXPECT_EQ((*(z.begin())).second, 1.1);

  EXPECT_EQ((*(++z.begin())).first, 2);
  EXPECT_EQ((*(++z.begin())).second, 2.2);

  EXPECT_EQ((*(++++z.begin())).first, 3);
  EXPECT_EQ((*(++++z.begin())).second, 3.3);
}

TEST(ZipTest, DifferentContainerSizes) {
  std::vector<int> v1{1, 2, 3};
  std::list<std::string> v2{"a", "b", "c", "d"};

  auto z = zip(v1, v2);

  int cnt;
  cnt = 0;
  for (auto i : z) {
    cnt++;
  }

  EXPECT_TRUE(cnt == 3);
}

TEST(ZipTest, EmptyContainer) {
  std::vector<int> v1{};
  std::vector<double> v2{1.1, 2.2, 3.3};

  auto z = zip(v1, v2);

  EXPECT_TRUE(z.end() == z.begin());
}