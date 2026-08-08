class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int prevnodelete = nodelete;
            nodelete = max(nodelete + arr[i], arr[i]);

            if (onedelete == INT_MIN) {
                onedelete = prevnodelete;
            } else {
                onedelete = max(onedelete + arr[i], prevnodelete);
            }

            ans = max(ans, max(onedelete, nodelete));
        }
        return ans;
    }
};