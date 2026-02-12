#include <stdio.h>

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (nums == NULL || out_i == NULL || out_j == NULL || n < 2) {
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }

    return 0;
}
