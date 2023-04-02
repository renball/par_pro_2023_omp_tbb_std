// Copyright 2023 Yablonskiy Dmitriy
#include "../../../modules/task_1/yablonskiy_d_radixsort/radixsort.h"

#include <iostream>
#include <vector>
#include <cmath>

void radixSort(std::vector<int>& arr) {
    int num = 0;
    int maxv=0;
    for (int i = 0; i < arr.size(); i++) {
        if (maxv <= arr[i]) {
            maxv = arr[i];
        }
    }
    while (maxv > 0) {
        num++;
        maxv /= 10;
    }
    std::vector<int> temp(arr.size());
    for (int i = 0; i < num; i++) {
        std::vector<int> co(10);
        int exp = pow(10, i);
        for (int j = 0; j < arr.size(); j++) {
            int d = (arr[j] / exp) % 10;
            co[d]++;
        }
        for (int j = 1; j < co.size(); j++) {
            co[j] += co[j - 1];
        }
        for (int j = arr.size() - 1; j >= 0; j--) {
            int d = (arr[j] / exp) % 10;
            temp[co[d] - 1] = arr[j];
            co[d]--;
        }
        swap(arr, temp);
    }
}
