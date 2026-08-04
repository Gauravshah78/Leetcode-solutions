class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        vector<int> hash(b + 1, 0);
        for (int x : nums) {
            hash[x]++;
        }
        vector<int> ans;
        for (int i = a; i <= b; i++) {
            if (hash[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};