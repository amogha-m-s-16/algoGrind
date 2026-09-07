class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int trappedCnt = 0;
        int lowMax = 0, highMax = 0;

        while(low < high) {
            lowMax = max(lowMax, height[low]);
            highMax = max(highMax, height[high]);

            if(lowMax < highMax) {
                trappedCnt += lowMax - height[low];
                low++;
            }

            else {
                trappedCnt += highMax - height[high];
                high--;
            }
        }

        return trappedCnt;
    }
};