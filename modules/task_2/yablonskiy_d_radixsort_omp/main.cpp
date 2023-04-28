// Copyright 2023 Yablonskiy Dmitriy
#include "./radixsort_omp.h"
#include <gtest/gtest.h>
#include <vector>

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
  int exp[] = {23,  33,  43,  47,  51,  56,  56,  57,  57,  58,  59,  60,  60,
               61,  63,  64,  64,  65,  68,  69,  70,  70,  71,  72,  73,  74,
               75,  76,  77,  78,  79,  80,  81,  82,  82,  83,  84,  85,  86,
               86,  87,  87,  88,  89,  90,  91,  92,  93,  93,  94,  94,  95,
               98,  98,  98,  99,  99,  99,  99,  100, 100, 101, 102, 102, 103,
               104, 104, 105, 105, 106, 107, 108, 109, 109, 110, 110, 111, 112,
               113, 114, 115, 116, 118, 118, 118, 119, 119, 120, 122, 123, 124,
               125, 126, 128, 130, 132, 132, 134, 134, 135, 136, 138, 138, 140};
  int arr[] = {68,  69,  70,  70,  71,  98,  99,  99,  99,  72,  73,  74,  75,
               76,  77,  78,  79,  80,  99,  100, 100, 101, 102, 102, 103, 104,
               104, 105, 105, 106, 107, 108, 109, 109, 110, 110, 111, 112, 113,
               114, 115, 116, 118, 118, 83,  84,  85,  86,  86,  87,  87,  88,
               89,  90,  91,  92,  93,  93,  118, 119, 119, 120, 122, 123, 124,
               125, 126, 128, 130, 132, 132, 134, 134, 135, 136, 138, 138, 140,
               23,  33,  43,  47,  51,  56,  81,  82,  82,  94,  94,  95,  98,
               98,  56,  57,  57,  58,  59,  60,  60,  61,  63,  64,  64,  65};
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
