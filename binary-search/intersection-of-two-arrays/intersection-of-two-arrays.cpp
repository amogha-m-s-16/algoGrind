class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;

        for(int el: nums1) st.insert(el);

        for(int el: nums2) {
            if(st.find(el) != st.end()) {
                ans.push_back(el);
                st.erase(el);
            }
        }

        return ans;
    }
};