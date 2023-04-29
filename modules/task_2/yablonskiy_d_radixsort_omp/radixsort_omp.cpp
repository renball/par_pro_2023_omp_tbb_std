// Copyright 2023 Yablonskiy Dmitriy
#include "../../../modules/task_2/yablonskiy_d_radixsort_omp/radixsort_omp.h"

int getMax(std::vector<int>* vec) {
  std::vector<int>& arr = *vec;
  int maxNum = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] > maxNum) {
      maxNum = arr[i];
    }
  }
  return maxNum;
}

void radixSortForExp(std::vector<int>* vec, int exp) {
  std::vector<int>& arr = *vec;
  int n = arr.size();
  std::vector<int> output(n);
  std::vector<int> count(10, 0);

  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(std::vector<int>* vec) {
  int maxNum = getMax(vec);

  for (int exp = 1; maxNum / exp > 0; exp *= 10) {
    radixSortForExp(vec, exp);
  }
}

std::vector<int> merge(std::vector<int>* firstVec, std::vector<int>* secondVec) {
  std::vector<int> temp(firstVec->size() + secondVec->size());
  std::merge((*firstVec).begin(), (*firstVec).end(), (*secondVec).begin(),
             (*secondVec).end(), temp.begin());
  return temp;
}

std::vector<int> radixSortMerge(std::vector<int>* vec) {
  const int vectorSize = (*vec).size();
  if (vectorSize == 0) throw -1;

  std::vector<int> result;

#pragma omp parallel
  {
      int thread = omp_get_thread_num();
      int threadNum = omp_get_num_threads();

      int vecSize = vec->size();
      int step = vecSize / threadNum;
      int leftOffset = step * thread;
      int rightOffset = step * (thread + 1);
      if ((vecSize / threadNum != 0) && (thread == threadNum - 1)) {
        rightOffset += vecSize - step * threadNum;
      }
      std::vector<int> localVec((*vec).begin() + leftOffset,
                                (*vec).begin() + rightOffset);

      radixSort(&localVec);

#pragma omp critical
      {
          result = merge(&result, &localVec);
      }
  }

  return result;
}

std::vector<int> getRandomVector(int size) {
  if (size <= 0) {
    throw(-1);
  }

  std::vector<int> randomVector(size);

  std::random_device dev;
  std::mt19937 gen(dev());

  for (int i = 0; i < size; i++) {
    randomVector[i] = gen() % 1000;
  }

  return randomVector;
}
