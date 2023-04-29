// Copyright 2023 Yablonskiy Dmitriy

#ifndef MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
#define MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_

#include <omp.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

int getMax(std::vector<int>* vec);

void radixSortForExp(std::vector<int>* vec, int exp);

void radixSort(std::vector<int>* vec);

std::vector<int> merge(std::vector<int>* firstVec, std::vector<int>* secondVec);

std::vector<int> radixSortMerge(std::vector<int>* vec);

std::vector<int> getRandomVector(int size);

#endif  // MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
