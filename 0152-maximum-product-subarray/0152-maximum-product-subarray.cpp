class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minending = nums[0];
        int maxending = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = nums[i];
            int b = minending * nums[i];
            int c = maxending * nums[i];

            minending = min(a, min(b, c));
            maxending = max(a, max(b, c));
            ans = max(ans, max(minending, maxending));
        }
        return ans;
    }
};