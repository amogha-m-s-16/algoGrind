class Solution {
private:
    int maxEle(vector<vector<int>>& arr, int col) {
        int maxVal = INT_MIN, ind = -1;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i][col] > maxVal) {
                maxVal = arr[i][col];
                ind = i;
            }
        }

        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = maxEle(mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
            int right = mid + 1 < mat[0].size() ? mat[row][mid + 1] : INT_MIN;

            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < left) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};