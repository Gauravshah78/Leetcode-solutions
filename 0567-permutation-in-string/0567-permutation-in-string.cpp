class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        unordered_map<char, char> f1, f2;

        for (char c : s1)
            f1[c]++;

        int low = 0;
        int high = 0;
        for (high = 0; high < m; high++) {
            f2[s2[high]]++;
            if (high - low + 1 > n) {
                f2[s2[low]]--;

                if (f2[s2[low]] == 0)
                    f2.erase(s2[low]);
                low++;
            }
            if (high - low + 1 == n) {
                if (f1 == f2)
                    return true;
            }
        }
        return false;
    }
};