class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int low = 0, high = height.size() - 1;

        while(low < high) {
            int breadth = high - low;
            int length = min(height[low], height[high]);

            int currentArea = length * breadth;
            maxArea = max(maxArea, currentArea);

            if(height[low] < height[high]) low++;
            else if(height[low] > height[high]) high--;
            else {
                low++;
                high--;
            }
        }
        
        return maxArea;
    }
};