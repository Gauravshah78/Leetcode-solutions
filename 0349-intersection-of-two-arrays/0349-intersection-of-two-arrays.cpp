class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        vector<int> ans;
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr1[i]) {
                j++;
            } else {
                if (ans.empty() || ans.back() != arr1[i])
                    ans.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};