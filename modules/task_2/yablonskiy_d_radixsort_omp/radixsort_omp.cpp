// Copyright 2023 Yablonskiy Dmitriy
#include "../../../modules/task_2/yablonskiy_d_radixsort_omp/radixsort_omp.h"
#include <cmath>
#include <iostream>
#include <vector>

int getDigit(int number, int k) { return (number / (int)pow(10, k)) % 10; }
void countSort(int *arr, int n, int k, int *out) {
  int count[10] = {0};
#pragma omp parallel for shared(count)
  for (int i = 0; i < n; i++) {
    count[getDigit(arr[i], k)]++;
  }
  int sum = 0;
  int temp[10];
  for (int i = 0; i < 10; i++) {
    sum += count[i];
    temp[i] = sum;
  }
#pragma omp parallel for shared(out)
  for (int i = n - 1; i >= 0; i--) {
    int digit = getDigit(arr[i], k);
    out[temp[digit] - 1] = arr[i];
    temp[digit]--;
  }
}
void radixSort(int *arr, int n) {
  int *temp = new int[n];

  for (int k = 0; k < 9; k++) {
    countSort(arr, n, k, temp);
    countSort(temp, n, k, arr);
  }
  delete[] temp;
}
void merge(int *arr, int *temp, int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    temp[k] = arr[i];
    k++;
    i++;
  }
  while (j <= right) {
    temp[k] = arr[j];
    k++;
    j++;
  }
  for (int k = left; k <= right; k++) {
    arr[k] = temp[k];
  }
}
void mergeSortParallel(int *arr, int *temp, int left, int right,
                       int numThreads) {
  if (left < right) {
    int mid = (left + right) / 2;
    if (numThreads > 1) {
#pragma omp parallel sections
      {
#pragma omp section
        { mergeSortParallel(arr, temp, left, mid, numThreads / 2); }
#pragma omp section
        {
          mergeSortParallel(arr, temp, mid + 1, right,
                            numThreads - numThreads / 2);
        }
      }
    } else {
      mergeSortParallel(arr, temp, left, mid, 1);
      mergeSortParallel(arr, temp, mid + 1, right, 1);
    }
    merge(arr, temp, left, mid, right);
  }
}
void mergeSort(int *arr, int n) {
  int *temp = new int[n];
  mergeSortParallel(arr, temp, 0, n - 1, omp_get_max_threads());
  delete[] temp;
}