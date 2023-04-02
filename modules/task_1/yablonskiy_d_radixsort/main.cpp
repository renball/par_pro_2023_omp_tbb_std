// Copyright 2023 Yablonskiy Dmitriy
#include <gtest/gtest.h>
#include <vector>
#include "./radixsort.h"

TEST(RadixSortTest, SortsArray) {
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    arr = radixSort(arr);
    std::vector<int> expec = { 2, 24, 45, 66, 75, 90, 170, 802 };
    EXPECT_EQ(arr, expec);
}

TEST(RadixSortTest, ArrayOfRightElements) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    arr = radixSort(arr);
    std::vector<int> expec = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(arr, expec);
}

TEST(RadixSortTest, ArrayOfSameElements) {
    std::vector<int> arr = { 1, 1, 1, 1, 1 };
    arr = radixSort(arr);
    std::vector<int> expec = { 1, 1, 1, 1, 1 };
    EXPECT_EQ(arr, expec);
}

TEST(RadixSortTest, ArrayOfSameElements_2) {
    std::vector<int> arr = { 2, 2, 2, 2, 2 };
    arr = radixSort(arr);
    std::vector<int> expec = { 2, 2, 2, 2, 2 };
    EXPECT_EQ(arr, expec);
}

TEST(RadixSortTest, ArrayOfSameElements_3) {
    std::vector<int> arr = { 3, 3, 3, 3, 3 };
    arr = radixSort(arr);
    std::vector<int> expec = { 3, 3, 3, 3, 3 };
    EXPECT_EQ(arr, expec);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}