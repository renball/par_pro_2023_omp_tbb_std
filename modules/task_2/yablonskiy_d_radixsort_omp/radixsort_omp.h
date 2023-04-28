// Copyright 2023 Yablonskiy Dmitriy

#ifndef MODULES_TASK_1_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
#define MODULES_TASK_1_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_

#include <vector>
#include <random>
#include <ctime>
#include <omp.h>
#include <algorithm>
#include <cmath>

int getDigit(int number, int k);
void countSort(int* arr, int n, int k, int* out);
void radixSort(int* arr, int n);
void merge(int* arr, int* temp, int left, int mid, int right);
void mergeSortParallel(int* arr, int* temp, int left, int right, int numThreads);
void mergeSort(int* arr, int n);
#endif  // MODULES_TASK_1_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
