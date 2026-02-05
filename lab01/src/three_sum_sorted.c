int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (n < 3) {
        return 0; //
    }
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;  // This is our 'j'
        int right = n - 1; // This is our 'k'

        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            if (current_sum == 0) {
                *out_i = i;
                *out_j = left;
                *out_k = right;
                return 1; //
            } 
            else if (current_sum < 0) {
                left++; //
            } 
            else {
                right--; //
            }
        }
    }
    return 0; 
}