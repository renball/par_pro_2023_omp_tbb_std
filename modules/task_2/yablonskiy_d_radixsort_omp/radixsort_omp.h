// Copyright 2023 Yablonskiy Dmitriy

#ifndef MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
#define MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_

#include <algorithm>
#include <cmath>
#include <omp.h>
#include <random>
#include <vector>

using namespace std;

int max_elem(vector<int> *v);
void radix_sort_e(vector<int> *v, int exp);
void radix_sort(vector<int> *v);
vector<int> merge(vector<int> *v1, vector<int> *v2);
vector<int> radix_sort_mer(vector<int> *v);
vector<int> create_rand_vec(int s);
#endif // MODULES_TASK_2_YABLONSKIY_D_RADIXSORT_OMP_RADIXSORT_OMP_H_
