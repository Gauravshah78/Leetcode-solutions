class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int minending = nums[0];
        int maxending = nums[0];
        
        int total = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for (int i = 1; i < n; i++) {
            total += nums[i];
            maxending = max(nums[i], maxending + nums[i]);
            minending = min(nums[i], minending + nums[i]);

            maxsum = max(maxsum, maxending);
            minsum = min(minsum, minending);
        }
        if (maxending < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};