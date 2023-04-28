// Copyright 2023 Yablonskiy Dmitriy
#include <gtest/gtest.h>
#include "./radixsort_omp.h"

TEST(RadixSortOpenMP, Test1) {
  int arr[] = {7, 2, 1, 6, 8, 5, 3, 9, 4};
  int exp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    EXPECT_EQ(arr[i], exp[i]);
  }
}
TEST(RadixSortOpenMP, Test2) {
  int arr[] = {5, 4, 3, 2, 1};
  int exp[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    EXPECT_EQ(arr[i], exp[i]);
  }
}
TEST(RadixSortOpenMP, Test3) {
  int arr[] = {3, 3, 3, 3, 3};
  int exp[] = {3, 3, 3, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    EXPECT_EQ(arr[i], exp[i]);
  }
}
TEST(RadixSortOpenMP, Test4) {
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int exp[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    EXPECT_EQ(arr[i], exp[i]);
  }
}
TEST(RadixSortOpenMP, Test5) {
  int arr[] = {212, 123, 830, 542, 150, 960, 276, 380, 199, 999};
  int exp[] = {123, 150, 199, 212, 276, 380, 542, 830, 960, 999};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  for (int i = 0; i < n; i++) {
    EXPECT_EQ(arr[i], exp[i]);
  }
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
