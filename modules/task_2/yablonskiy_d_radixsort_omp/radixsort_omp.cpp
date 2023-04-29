// Copyright 2023 Yablonskiy Dmitriy
#include "../../../modules/task_2/yablonskiy_d_radixsort_omp/radixsort_omp.h"

#include <omp.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

int max_elem(std::vector<int> *v) {
  std::vector<int> &mas = *v;
  int max = mas[0];
  for (int i = 1; i < mas.size(); i++) {
    if (mas[i] > max)
      max = mas[i];
  }
  return max;
}

void radix_sort_e(std::vector<int> *v, int exp) {
  std::vector<int> &mas = *v;
  int s = mas.size();
  std::vector<int> tmp(s);
  std::vector<int> num(10, 0);
  for (int i = 0; i < s; i++)
    num[(mas[i] / exp) % 10]++;
  for (int i = 1; i < 10; i++)
    num[i] += num[i - 1];
  for (int i = s - 1; i >= 0; i--) {
    tmp[num[(mas[i] / exp) % 10] - 1] = mas[i];
    num[(mas[i] / exp) % 10]--;
  }
  for (int i = 0; i < s; i++)
    mas[i] = tmp[i];
}

void radix_sort(std::vector<int> *v) {
  int max = max_elem(v);
  for (int exp = 1; max / exp > 0; exp *= 10)
    radix_sort_e(v, exp);
}

std::vector<int> merge(std::vector<int> *v1, std::vector<int> *v2) {
  std::vector<int> res(v1->size() + v2->size());
  merge((*v1).begin(), (*v1).end(), (*v2).begin(), (*v2).end(), res.begin());
  return res;
}

std::vector<int> radix_sort_mer(std::vector<int> *v) {
  const int s = (*v).size();
  if (s == 0)
    throw -1;
  std::vector<int> result;

#pragma omp parallel
  {
    int thread = omp_get_thread_num();
    int threadNum = omp_get_num_threads();

    int s = v->size();
    int step = s / threadNum;
    int leftOffset = step * thread;
    int rightOffset = step * (thread + 1);
    if ((s / threadNum != 0) && (thread == threadNum - 1))
      rightOffset += s - step * threadNum;
    std::vector<int> tmp((*v).begin() + leftOffset, (*v).begin() + rightOffset);
    radix_sort(&tmp);

#pragma omp critical
    { result = merge(&result, &tmp); }
  }
  return result;
}

std::vector<int> create_rand_vec(int s) {
  if (s <= 0)
    throw(-1);
  std::vector<int> v(s);
  std::random_device dev;
  std::mt19937 gen(dev());
  for (int i = 0; i < s; i++)
    v[i] = gen() % 1000;
  return v;
}
