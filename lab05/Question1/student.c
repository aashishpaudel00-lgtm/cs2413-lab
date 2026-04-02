#include <stdio.h>
#include <stdlib.h>

// Question 1: Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == complement) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return result;
}

// Question 2: Kth Largest Element
int findKthLargest(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return nums[k - 1];
}