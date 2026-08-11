class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;
        for (int i = 0; i < ransom.size(); i++) {
            need[ransom[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++) {
            have[magazine[i]]++;
        }
        for (auto i : need) {
            char ch = i.first;
            int freq = i.second;
            if (have[ch] < freq) {
                return false;
            }
        }
        return true;
    }
};