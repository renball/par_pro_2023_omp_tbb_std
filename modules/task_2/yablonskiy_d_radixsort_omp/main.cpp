// Copyright 2023 Yablonskiy Dmitriy
#include <gtest/gtest.h>
#include "./radixsort_omp.h"

TEST(OMP, test_zero_size_vector) {
  std::vector<int> vec = {};
  ASSERT_ANY_THROW(radixSortMerge(&vec));
}

TEST(OMP, test_sorted_vector) {
  std::vector<int> sortedVec = create_rand_arr(10);
  std::sort(sortedVec.begin(), sortedVec.end());

  std::vector<int> vec = radixSortMerge(&sortedVec);

  ASSERT_EQ(vec, sortedVec);
}

TEST(OMP, test_random_vector_small_size) {
  const int vectorSize = 10;
  std::vector<int> vec1 = create_rand_arr(vectorSize);

  std::vector<int> vec2 = radixSortMerge(&vec1);
  std::sort(vec1.begin(), vec1.end());

  ASSERT_EQ(vec1, vec2);
}

TEST(OMP, test_random_vector_medium_size) {
  const int vectorSize = 250;
  std::vector<int> vec1 = create_rand_arr(vectorSize);

  std::vector<int> vec2 = radixSortMerge(&vec1);
  std::sort(vec1.begin(), vec1.end());

  ASSERT_EQ(vec1, vec2);
}

TEST(OMP, test_random_vector_large_size) {
  const int vectorSize = 1000000;
  std::vector<int> vec1 = create_rand_arr(vectorSize);

  std::vector<int> vec2 = radixSortMerge(&vec1);
  std::sort(vec1.begin(), vec1.end());

  ASSERT_EQ(vec1, vec2);
}
