class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minending = nums[0];
        int maxending = nums[0];
        int ans = abs(nums[0]);

        for (int i = 1; i < n; i++) {
            int a = nums[i];
            int b = minending + nums[i];
            int c = maxending + nums[i];

            minending = min(a, min(b, c));
            maxending = max(a, max(b, c));

            ans = max(ans, abs(maxending));
            ans = max(ans, abs(minending));
        }
        return ans;
    }
};