class Solution {
public:
    int find(unordered_map<int, int>& mp) {
        int maxfreq = 0;

        for (auto& it : mp) {
            maxfreq = max(maxfreq, it.second);
        }

        return maxfreq;
    }
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int res = 0;

        unordered_map<int, int> mp;

        for (high = 0; high < n; high++) {
            mp[nums[high]]++;

            int zeros = mp[0];

            while (zeros > k) {
                mp[nums[low]]--;
                low++;

                zeros = mp[0];
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};