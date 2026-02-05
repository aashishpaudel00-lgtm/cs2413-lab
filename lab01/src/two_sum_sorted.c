int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    int left = 0;      
    int right = n - 1;   
    while (left < right) {
        int current_sum = nums[left] + nums[right];
        if (current_sum == target) {
            *out_i = left;
            *out_j = right;
            return 1;
        } 
        else if (current_sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }
    return 0;
}