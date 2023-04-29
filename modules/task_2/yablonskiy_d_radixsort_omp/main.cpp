// Copyright 2023 Yablonskiy Dmitriy
#include "./radixsort_omp.h"
#include <gtest/gtest.h>


TEST(radix_sort_omp, TEST_sort_vec_size_zero) {
  std::vector<int> v = {};
  ASSERT_ANY_THROW(radix_sort_mer(&v));
}

TEST(radix_sort_omp, TEST_sorted_vector) {
  std::vector<int> v_sorted = create_rand_vec(10);
  std::vector<int> v_expect;
  v_expect = v_sorted;

  std::sort(v_sorted.begin(), v_sorted.end());

  std::vector<int> v = radix_sort_mer(&v_expect);

  ASSERT_EQ(v, v_sorted);
}

TEST(radix_sort_omp, TEST_sort_rand_vec_s_10) {
  const int s = 10;
  std::vector<int> v1 = create_rand_vec(s);

  std::vector<int> v2 = radix_sort_mer(&v1);
  std::sort(v1.begin(), v1.end());

  ASSERT_EQ(v1, v2);
}

TEST(radix_sort_omp, TEST_sort_rand_vec_s_1000) {
  const int s = 1000;
  std::vector<int> v1 = create_rand_vec(s);

  std::vector<int> v2 = radix_sort_mer(&v1);
  std::sort(v1.begin(), v1.end());

  ASSERT_EQ(v1, v2);
}

TEST(radix_sort_omp, TEST_sort_rand_vec_s_65536) {
  const int s = 65536;
  std::vector<int> v1 = create_rand_vec(s);

  std::vector<int> v2 = radix_sort_mer(&v1);
  std::sort(v1.begin(), v1.end());

  ASSERT_EQ(v1, v2);
}
