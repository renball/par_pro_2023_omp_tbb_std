// Copyright 2023 Yablonskiy Dmitriy
#include "../../../modules/task_3/yablonskiy_d_radixsort_tbb/radixsort.h"

int max_elem(std::vector<int>* arr) {
  std::vector<int>& mass = *arr;
  int maximum = mass[0];
  for (int i = 1; i < mass.size(); i++) {
    if (mass[i] > maximum) {
      maximum = mass[i];
    }
  }
  return maximum;
}

void radix_sort_e(std::vector<int>* arr, int exp) {
  std::vector<int>& mass = *arr;
  int n = mass.size();
  std::vector<int> o(n);
  std::vector<int> c(10, 0);

  for (int i = 0; i < n; i++) {
    c[(mass[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    c[i] += c[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    o[c[(mass[i] / exp) % 10] - 1] = mass[i];
    c[(mass[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    mass[i] = o[i];
  }
}

void radix_sort(std::vector<int>* arr) {
  int maximum = max_elem(arr);

  for (int exp = 1; maximum / exp > 0; exp *= 10) {
    radix_sort_e(arr, exp);
  }
}

std::vector<int> radix_m(const std::vector<int>& arr_1, const std::vector<int>& arr_2) {
  std::vector<int> t(arr_1.size() + arr_2.size());
  std::merge(arr_1.begin(), arr_1.end(), arr_2.begin(),
             arr_2.end(), t.begin());
  return t;
}

class radixSorting {
 public:
  mutable std::vector<int> result;
  radixSorting() = default;
  radixSorting(const radixSorting& o, tbb::split) {}

  void operator()(const tbb::blocked_range<std::vector<int>::iterator>& r) {
    std::copy(r.begin(), r.end(), std::back_inserter(result));
    radix_sort(&result);
  }

  void join(const radixSorting& rhs) {
    result = radix_m(rhs.result, result);
  }
};

std::vector<int> radix_sort_mer(std::vector<int>* arr) {
  const int arr_size = (*arr).size();
  if (arr_size == 0) throw -1;

  std::vector<int> t(*arr);
  radixSorting sorting;

  tbb::parallel_reduce(
      tbb::blocked_range<std::vector<int>::iterator>(t.begin(), t.end()),
                       sorting);

  return sorting.result;
}

std::vector<int> create_rand_arr(int size) {
  if (size <= 0) {
    throw(-1);
  }

  std::vector<int> rand_arr(size);

  std::random_device dev;
  std::mt19937 gen(dev());

  for (int i = 0; i < size; i++) {
    rand_arr[i] = gen() % 1000;
  }

  return rand_arr;
}
