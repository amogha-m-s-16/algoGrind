class Solution {
private:
    int countBouquets(vector<int>& bloomDay, int bouqs, int m, int k) {
        int noOfBocq = 0, count = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= bouqs) count++;

            else {
                noOfBocq += (count / k);
                count = 0;
            }
        }

        noOfBocq += (count / k);
        return noOfBocq >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;

        int low = INT_MAX, high = INT_MIN;

        for(int i = 0; i < bloomDay.size(); i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while(low <= high) {
            int mid = (low + high) / 2;

            if(countBouquets(bloomDay, mid, m, k))  high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};