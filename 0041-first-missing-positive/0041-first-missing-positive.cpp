class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int x : arr) {
            mp[x]++;
        }
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                return  i;
            }
        }
        return n + 1;
    }
};