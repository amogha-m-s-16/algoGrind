class Solution {
private:
    vector<int> findNextSmallEle(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;

        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            ans[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findPrevSmallEle(vector<int> arr) {
        vector<int> ans(arr.size());
        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmallEle = findNextSmallEle(arr);
        vector<int> prevSmallEle = findPrevSmallEle(arr);
        int total = 0, mod = (int) (1e9 + 7);

        for(int i = 0; i < arr.size(); i++) {
            int left = i - prevSmallEle[i];
            int right = nextSmallEle[i] - i;

            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }

        return total;
    }
};