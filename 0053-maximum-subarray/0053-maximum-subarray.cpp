class Solution {
public:
    long long maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN;
        long long sum = 0;
        int start = 0;
        int ansstrt = -1, ansend = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) {
                start = i;
            }
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
                ansstrt = start;
                ansend = i;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};
