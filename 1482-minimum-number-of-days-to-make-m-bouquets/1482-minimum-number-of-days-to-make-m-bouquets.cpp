class Solution {
public:
    bool ispossible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;
        int n = arr.size();
        int bouquets = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
                if (cnt == k) {
                    bouquets++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long totalflower = 1LL * k * m;
        if (totalflower > arr.size())
            return -1;

        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());

        int low = mini;
        int high = maxi;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(arr, mid, m, k)) {

                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};