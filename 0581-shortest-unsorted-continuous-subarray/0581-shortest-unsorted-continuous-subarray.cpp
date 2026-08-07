class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSoFar = INT_MIN;
        int minSoFar = INT_MAX;

        int left = -1;
        int right = -1;

        for (int i = 0; i < n; i++) {

            maxSoFar = max(maxSoFar, nums[i]);

            if (nums[i] < maxSoFar)
                right = i;
        }

        for (int i = n - 1; i >= 0; i--) {

            minSoFar = min(minSoFar, nums[i]);

            if (nums[i] > minSoFar)
                left = i;
        }

        if (right == -1)
            return 0;

        return right - left + 1;
    }
};