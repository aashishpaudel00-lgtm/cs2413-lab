#include <stdio.h>

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (nums == NULL || out_i == NULL || out_j == NULL || n < 2) {
        return 0;
    }

    int i = 0;
    int j = n - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];

        if (sum == target) {
            *out_i = i;
            *out_j = j;
            return 1;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return 0;
}