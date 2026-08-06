class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = 0;
        int res = -1;
        unordered_map<int, int> mp;
        for (high = 0; high < n; high++) {
            mp[arr[high]]++;

            while (mp.size() > 2) {
                mp[arr[low]]--;
                if (mp[arr[low]] == 0) {
                    mp.erase(arr[low]);
                }
                low++;
            }

            if (mp.size() == 2 || mp.size() < 2) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }
        return res;
    }
};