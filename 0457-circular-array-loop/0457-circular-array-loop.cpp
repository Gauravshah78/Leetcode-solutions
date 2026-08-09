class Solution {
public:
    int nextIndex(vector<int>& nums, int curr) {
        int n = nums.size();
        return (curr + nums[curr] % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool dir = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // slow ka next
                int slowNext = nextIndex(nums, slow);

                // direction change
                if ((nums[slowNext] > 0) != dir)
                    break;

                // fast ka first step
                int fastNext = nextIndex(nums, fast);

                if ((nums[fastNext] > 0) != dir)
                    break;

                // fast ka second step
                int fastNext2 = nextIndex(nums, fastNext);

                if ((nums[fastNext2] > 0) != dir)
                    break;

                slow = slowNext;
                fast = fastNext2;

                if (slow == fast) {

                    // self loop: cycle length = 1
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};