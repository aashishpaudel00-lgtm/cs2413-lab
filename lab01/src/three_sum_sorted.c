#include <stdio.h>

/**
 * Finds three indices i < j < k such that nums[i] + nums[j] + nums[k] == 0.
 * The input array is already sorted.
 */
int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    // A triplet requires at least three elements.
    if (nums == NULL || n < 3) {
        return 0;
    }

    // Fix the first index 'i' and use two pointers for the rest.
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];

            if (current_sum == 0) {
                // Success! Store the indices and return 1.
                *out_i = i;
                *out_j = left;
                *out_k = right;
                return 1;
            } else if (current_sum < 0) {
                // Sum is too small; move the left pointer forward.
                left++;
            } else {
                // Sum is too large; move the right pointer backward.
                right--;
            }
        }
    }

    // No valid triplet found.
    return 0;
}