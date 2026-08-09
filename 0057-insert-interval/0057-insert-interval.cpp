class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newarr) {

        if (arr.empty()) {
            arr.push_back(newarr);
            return arr;
        }
        int k = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] <= newarr[0]) {
                k++;
            }
        }

        arr.insert(arr.begin() + k, newarr);

        vector<vector<int>> res;
        int n = arr.size();

        int start1 = arr[0][0];
        int end1 = arr[0][1];

        for (int i = 1; i < n; i++) {
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if (end1 >= start2) {
                end1 = max(end1, end2);
                continue;
            }

            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1, end1});
        return res;
    }
};