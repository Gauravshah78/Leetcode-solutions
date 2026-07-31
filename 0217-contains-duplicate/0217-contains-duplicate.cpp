class Solution {
public:
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