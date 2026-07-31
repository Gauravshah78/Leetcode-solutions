class Solution {
public:
    // bool containsDuplicate(vector<int>& arr) {
    //     int n = arr.size();
    //     sort(arr.begin(), arr.end());
    //     for(int i=0; i<n; i++) {
    //         if(arr[0] == arr[1]) return true;
    //     }
    //     return false;
    // }

    bool containsDuplicate(vector<int> &arr) {
        int n=arr.size();
        unordered_set<int>st;
        for(int x : arr) {
            if(st.count(x)) {
                return true;
            }
            st.insert(x);
        }
        return false;
    }
};