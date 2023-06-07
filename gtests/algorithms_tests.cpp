#include <list>
#include "gtest/gtest.h"
#include "stack"

#include "algorithms.h"

using namespace algorithms;

TEST(AlgorithmsTest, AllOfTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::all_of(v.begin(), v.end(), [](int i) { return i > 0; }));
  EXPECT_FALSE(algorithms::all_of(v.begin(), v.end(), [](int i) { return i > 3; }));
}

TEST(AlgorithmsTest, AnyOfTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::any_of(v.begin(), v.end(), [](int i) { return i == 3; }));
  EXPECT_FALSE(algorithms::any_of(v.begin(), v.end(), [](int i) { return i > 5; }));
}

TEST(AlgorithmsTest, NoneOfTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::none_of(v.begin(), v.end(), [](int i) { return i == 6; }));
  EXPECT_FALSE(algorithms::none_of(v.begin(), v.end(), [](int i) { return i < 5; }));
}

TEST(AlgorithmsTest, OneOfTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::one_of(v.begin(), v.end(), [](int i) { return i == 3; }));
  EXPECT_FALSE(algorithms::one_of(v.begin(), v.end(), [](int i) { return i > 3; }));
}

TEST(AlgorithmsTest, IsSortedTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::is_sorted(v.begin(), v.end()));
  std::vector<int> v2{5, 4, 3, 2, 1};
  EXPECT_FALSE(algorithms::is_sorted(v2.begin(), v2.end()));
  std::vector<int> v3{1, 3, 2, 4, 5};
  EXPECT_FALSE(algorithms::is_sorted(v3.begin(), v3.end()));
  std::vector<int> v4{};
  EXPECT_TRUE(algorithms::is_sorted(v4.begin(), v4.end()));
}

TEST(AlgorithmsTest, IsSortedPredicateTest) {
  std::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_TRUE(algorithms::is_sorted(v.begin(), v.end(), [](int a, int b) { return a < b; }));
  std::vector<int> v2{5, 4, 3, 2, 1};
  EXPECT_FALSE(algorithms::is_sorted(v2.begin(), v2.end(), [](int a, int b) { return a < b; }));
  std::vector<int> v3{1, 3, 2, 4, 5};
  EXPECT_FALSE(algorithms::is_sorted(v3.begin(), v3.end(), [](int a, int b) { return a < b; }));
  std::vector<int> v4{};
  EXPECT_TRUE(algorithms::is_sorted(v4.begin(), v4.end(), [](int a, int b) { return a < b; }));
}

TEST(IsPartitionedTest, PartitionedVector) {
  std::vector<int> v = {4, 2, 124, 3, 5, 1};
  auto result = algorithms::is_partitioned(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
  EXPECT_TRUE(result);
}

TEST(IsPartitionedTest, NonPartitionedVector) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  auto result = algorithms::is_partitioned(v.begin(), v.end(), [](int x){ return x > 3; });
  EXPECT_FALSE(result);
}

TEST(FindNotTest, FoundValue) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto result = algorithms::find_not(v.begin(), v.end(), 3);
  EXPECT_EQ(*result, 1);
}

TEST(FindNotTest, NotFoundValue) {
  std::vector<int> v = {6, 6, 6, 6, 6};
  auto result = algorithms::find_not(v.begin(), v.end(), 6);
  EXPECT_EQ(result, v.end());
}

TEST(FindBackwardTest, FoundValue) {
  std::deque<int> d = {1, 2, 3, 2, 5};
  auto result = algorithms::find_backward(d.begin(), d.end(), 2);
  EXPECT_EQ(*result, 2);
}

TEST(FindBackwardTest, NotFoundValue) {
  std::deque<int> d = {1, 2, 3, 2, 5};
  auto result = algorithms::find_backward(d.begin(), d.end(), 6);
  EXPECT_EQ(result, d.end());
}

TEST(IsPalindromeTest, EmptyVector) {
  std::vector<int> v = {};
  auto result = algorithms::is_palindrome(v.begin(), v.end());
  EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, SingleValueVector) {
  std::vector<int> v = {1};
  auto result = algorithms::is_palindrome(v.begin(), v.end());
  EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, PalindromeVector) {
  std::vector<int> v = {1, 2, 3, 2, 1};
  auto result = algorithms::is_palindrome(v.begin(), v.end());
  EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, NonPalindromeVector) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto result = is_palindrome(v.begin(), v.end());
  EXPECT_FALSE(result);
}

TEST(IsPalindromeTest, PalindromeString) {
  std::string s = "racecar";
  auto result = is_palindrome(s.begin(), s.end());
  EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, NonPalindromeString) {
  std::string s = "hello";
  auto result = is_palindrome(s.begin(), s.end());
  EXPECT_FALSE(result);
}

TEST(IsPalindromeTest, NonBidirectional) {
  std::list<int> v = {1, 2, 3, 2, 1};
  auto result = is_palindrome(v.begin(), v.end());
  EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, PalindromeString2) {
  std::string s = "hello";
  auto result = is_palindrome(s.begin(), s.end(), [](char x, char y){ return x != y; });
  EXPECT_TRUE(result);
}