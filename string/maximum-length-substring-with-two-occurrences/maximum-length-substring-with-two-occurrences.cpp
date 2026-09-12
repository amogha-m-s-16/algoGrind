class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mpp;
        int i = 0, j = 0, n = s.size();
        int ans = 0;

        while(j < n) {
            mpp[s[j]]++;

            while(mpp[s[j]] > 2) {
                mpp[s[i]]--;
                i ++;
            }    

            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};