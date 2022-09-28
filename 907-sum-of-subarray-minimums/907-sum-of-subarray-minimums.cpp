class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {	
        int n = arr.size(), ans = 0, mod = 1e9+7;
        vector<int> left(n) , right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (not st.empty() and arr[st.top()] > arr[i]) st.pop();
            if (st.size() > 0) 
                left[i] = i - st.top();
            else 
                left[i] = i+1;
            st.push(i);
        }
        while (not st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (not st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if (st.size() > 0) right[i] = st.top() - i;
            else right[i] = n-i;
            st.push(i);
        }

        for(int i = 0; i < n; ++i) {
            long long int prod = (left[i] * right[i]) % mod;
            long long int num = (arr[i] * prod) % mod;
            ans = (ans + num) % mod;
        }
        return ans % mod;
    }
};