class Solution {
private:
    int calculateHours(vector<int>& piles, int speed, int h) {
        long long totalHour = 0;

        for(int banana : piles) {
            long long div = banana / speed;
            totalHour += div;

            if(banana % speed != 0) totalHour++;
        }

        return totalHour <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(calculateHours(piles, mid, h)) high = mid - 1;
            else low = mid + 1; 
        }

        return low;
    }
};