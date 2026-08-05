class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                // positive
                neg.push_back(nums[i]);

            else {
                pos.push_back(nums[i]);
            }
        }
        if (neg.size() == 0) {
            for (int i = 0; i < n; i++)
                pos[i] *= pos[i];

            return pos;
        }
        if (pos.size() == 0) {
            for (int i = 0; i < n; i++)
                neg[i] *= neg[i];
            reverse(neg.begin(), neg.end());
            return neg;
        }
        int i = 0;
        int j = 0;
        int id = 0;
        int a = neg.size();
        int b = pos.size();

        vector<int> ans(a + b);
        for (int i = 0; i < a; i++)
            neg[i] *= neg[i];
        reverse(neg.begin(), neg.end());

        for (int i = 0; i < b; i++)
            pos[i] *= pos[i];
        while (i < a && j < b) {
            if (neg[i] <= pos[j]) {
                ans[id] = neg[i];
                id++;
                i++;
            } else {
                ans[id] = pos[j];
                id++;
                j++;
            }
        }
        while (i < a) {
            ans[id] = neg[i];
            id++;
            i++;
        }
        while (j < b) {
            ans[id] = pos[j];
            id++;
            j++;
        }
        return ans;
    }
};