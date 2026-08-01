class Solution {
public:
    long long solve(vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
        if (l == r) {
            return arr[l];
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        long long takeleft = arr[l] - solve(arr, l + 1, r, dp);
        long long takeright = arr[r] - solve(arr, l, r - 1, dp);
        return dp[l][r] = max(takeleft, takeright);
    }
    bool predictTheWinner(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 0, n - 1, dp) >= 0;
    }
};