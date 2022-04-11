// Time Complexity - O(m * n)
// Space Complexity - O(m * n)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {                
                // j + k  => gives new y-axis of element
                // (j+k)/n => no. of times rows are to be changed due to out-of-bound
                // % m,  % n   => so that idx are in-bound 
                int newX = (i + ( (j + k) / n)) % m;
                int newY = (j + k) % n;

                ans[newX][newY] = grid[i][j];
            }
        }
        
        return ans;
    }
};