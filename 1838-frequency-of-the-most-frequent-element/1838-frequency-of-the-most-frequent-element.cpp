class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxfreq = 1;
        sort(nums.begin(), nums.end());

        int count = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while ((long long)nums[i] * (i - count + 1) - sum > k) {
                sum -= nums[count];
                count++;
            }
            maxfreq = max(maxfreq, i - count + 1);
        }
        return maxfreq;
    }
};