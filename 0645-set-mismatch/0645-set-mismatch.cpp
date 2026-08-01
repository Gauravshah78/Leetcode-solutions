class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int x : arr) {
            mp[x]++;
        }
        int dup = -1;
        int miss = -1;
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                miss = i;
            } else if (mp[i] == 2)
                dup = i;
        }
        return {dup, miss};
    }
};