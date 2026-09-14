class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int trappedCnt = 0;

        while(left <= right) {
            if(height[left] <= height[right]) {

                if(leftMax >= height[left]) {
                    trappedCnt += leftMax - height[left];
                }
                else leftMax = height[left];

                left += 1;
            }

            else {

                if(rightMax >= height[right]) {
                        trappedCnt += rightMax - height[right];
                    }
                else rightMax = height[right];

                    right -= 1;
                }

            }

        return trappedCnt;
    }

};