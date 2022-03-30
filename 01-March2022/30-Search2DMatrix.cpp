// Time Complexity - O(logm + logn)
// Space Complexity - O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        
        // Find the row where element might be
        
        int low = 0, high = nRow-1, row = -1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target) {
                row = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }

        if(row == -1)   return false;
        
        // Find the element in this 'row'
        low = 0, high = nCol-1;
        while(low <= high) {
            int mid = (low + high)/2;

            if(matrix[row][mid] == target)          // Found the target
                return true;
            else if(matrix[row][mid] > target)      // Find the element on left side
                high = mid-1;
            else                                    // Find the element on right side
                low = mid+1;
        }
        
        // Target not found
        return false;
    }
};