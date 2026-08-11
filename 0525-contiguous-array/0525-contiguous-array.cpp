class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int ones = 0;
        
        unordered_map<int, int> f;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else {
                ones++;
            }
            int diff = zeros - ones;
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            }
            if (f.find(diff) == f.end()) {
                f[diff] = i;
            } else {
                int index = f[diff];
                int len = i - index;
                res = max(res, len);
            }
        }
        return res;
    }
};