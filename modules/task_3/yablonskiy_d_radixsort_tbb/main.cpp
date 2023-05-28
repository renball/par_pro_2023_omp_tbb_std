// Copyright 2023 Yablonskiy Dmitriy
#include <gtest/gtest.h>
#include "./radixsort.h"

TEST(TBB, test_zero_size_vector) {
  std::vector<int> arr = {};
  ASSERT_ANY_THROW(radix_sort_mer(&arr));
}

TEST(TBB, test_sorted_vector) {
  std::vector<int> arr_sorted = create_rand_arr(10);
  std::sort(arr_sorted.begin(), arr_sorted.end());

  std::vector<int> arr = radix_sort_mer(&arr_sorted);

  ASSERT_EQ(arr, arr_sorted);
}

TEST(TBB, test_random_vector_small_size) {
  const int arr_size = 10;
  std::vector<int> arr_first = create_rand_arr(arr_size);

  std::vector<int> arr_second = radix_sort_mer(&arr_first);
  std::sort(arr_first.begin(), arr_first.end());

  ASSERT_EQ(arr_first, arr_second);
}

TEST(TBB, test_random_vector_medium_size) {
  const int arr_size = 250;
  std::vector<int> arr_first = create_rand_arr(arr_size);

  std::vector<int> arr_second = radix_sort_mer(&arr_first);
  std::sort(arr_first.begin(), arr_first.end());

  ASSERT_EQ(arr_first, arr_second);
}

TEST(TBB, test_random_vector_large_size) {
  const int arr_size = 1000000;
  std::vector<int> arr_first = create_rand_arr(arr_size);

  std::vector<int> arr_second = radix_sort_mer(&arr_first);
  std::sort(arr_first.begin(), arr_first.end());

  ASSERT_EQ(arr_first, arr_second);
}
