// Copyright 2023 Yablonskiy Dmitriy

#ifndef MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
#define MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_

#include <algorithm>
#include <cmath>
#include <omp.h>
#include <random>
#include <vector>


int max_elem(std::vector<int> *v);
void radix_sort_e(std::vector<int> *v, int exp);
void radix_sort(std::vector<int> *v);
std::vector<int> merge(std::vector<int> *v1, std::vector<int> *v2);
std::vector<int> radix_sort_mer(std::vector<int> *v);
std::vector<int> create_rand_vec(int s);

#endif // MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
