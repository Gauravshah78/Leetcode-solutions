class Solution {
public:
    int sumby(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        if (n > threshold)
            return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sumby(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};