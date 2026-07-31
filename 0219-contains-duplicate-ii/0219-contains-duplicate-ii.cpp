class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        // int n = arr.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] == arr[j] && (j - i) <= k)
        //             return true;
        //     }
        // }
        // return false;

        
      int n=arr.size();
        unordered_set<int>st;
        for(int i=0; i<n; i++) {
            if(st.count(arr[i])) {
                return true;
            }
            
            st.insert(arr[i]);
            if(st.size() > k) {
                st.erase(arr[i-k]);
            } 
        }
        return false;
    }
};