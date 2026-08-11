class Solution {
public:
    vector<int> nextGreaterStack(vector<int>& a) {
        int n = a.size();
        
        vector<int> res(n);
        res[n - 1] = 0;
        
        stack<int> st;
        st.push(n - 1);
        
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nextGreaterStack(temperatures);
    }
};