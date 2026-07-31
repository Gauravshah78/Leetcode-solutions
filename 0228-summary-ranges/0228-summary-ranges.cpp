class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        vector<string> ans;
        int n = arr.size();
        if (n == 0)
            return ans;
        int strt = arr[0];
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || arr[i + 1] != arr[i] + 1) {
                if (strt == arr[i])
                    ans.push_back(to_string(strt));
                else
                    ans.push_back(to_string(strt) + "->" + to_string(arr[i]));
                if (i != n - 1)
                    strt = arr[i + 1];
            }
        }
        return ans;
    }
};