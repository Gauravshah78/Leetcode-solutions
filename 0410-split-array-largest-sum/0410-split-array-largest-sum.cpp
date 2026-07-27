class Solution {
public:
    int countPartitions(vector<int>& a, int maxSum) {
        int partitions = 1;   // at least one partition
        long subarraySum = 0; // sum of current subarray

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& a, int k) {
         int low = *max_element(a.begin(), a.end());   // Largest element
    int high = accumulate(a.begin(), a.end(), 0); // Sum of all elements

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int partitions = countPartitions(a, mid);

        if (partitions > k) {
            low = mid + 1;      // Too many partitions → increase maxSum
        } else {
            high = mid - 1;     // Valid → try smaller maxSum
        }
    }

    return low;
    }
};