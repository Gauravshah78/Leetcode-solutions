class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        int curr = 1;
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1])
                curr++;

            else
                curr = 1;
        
        maxi = max(maxi, curr);
    }
        return maxi;
    }
};