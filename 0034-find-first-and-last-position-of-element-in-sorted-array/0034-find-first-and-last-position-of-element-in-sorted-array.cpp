class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                res = mid;
                high = mid - 1;
            }
             else {
                low = mid + 1;
            }
        }
        return res;
    }
    int upperbound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerbound(nums, target);
        int n = nums.size();
        if(first == n || nums[first] != target) return {-1,-1};
        int second = upperbound(nums, target) - 1;
        return {first, second};
    }
};