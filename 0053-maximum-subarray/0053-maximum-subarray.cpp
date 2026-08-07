class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending = nums[0];
        int n = nums.size();
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            int a = bestending + nums[i];
            int b = nums[i];
            bestending = max(a, b);
            ans = max(ans, bestending);
        }
        return ans;
    }
};