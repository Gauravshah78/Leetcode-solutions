class Solution {
public:
    int find(unordered_map<char, int>& mp) {
        int maxfreq = 0;
        for (auto& it : mp) {
            maxfreq = max(maxfreq, it.second);
        }
        return maxfreq;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = 0;

        unordered_map<char, int> mp;
        for (high = 0; high < n; high++) {
            mp[s[high]]++;
            int len = high - low + 1;
            int maxfreq = find(mp);
            int diff = len - maxfreq;
            while (diff > k) {
                mp[s[low]]--;
                low++;

                len = high - low + 1;
                maxfreq = find(mp);
                diff = len - maxfreq;
            }
            res = max(res, len);
        }
        return res;
    }
};