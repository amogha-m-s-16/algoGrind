class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixRes = 1, suffixRes = 1;
        int ans = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(prefixRes == 0) prefixRes = 1;
            if(suffixRes == 0) suffixRes = 1;

            prefixRes *= nums[i];
            suffixRes *= nums[nums.size() - i - 1];

            ans = max(ans, max(prefixRes, suffixRes));
        }

        return ans;
    }
};