class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        int cntZero = 0;

        for (int x : nums) {
            xr ^= x;

            if (x == 0) {
                cntZero++;
            }
        }
        // case 1
        if (xr != 0) {
            return n;
        }

        // Case 3
        if (cntZero == n) {
            return 0;
        }

        // Case 2
        return n - 1;
    }
};