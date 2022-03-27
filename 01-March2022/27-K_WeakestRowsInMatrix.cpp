class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;
        
        int nRow = mat.size(), nCol = mat[0].size();
        for(int row = 0; row < nRow; ++row) {
            int col = 0;
            
            // It gives no. of soldiers in this row
            for(; col < nCol; ++col) {
                if(mat[row][col] == 0)          // Here we can use binary search if we want,
                    break;                      // it decreases time complexity from m -> logm
            }
            ans.push_back({col, row});
        }
        
        // Sort rows according to no.of soldiers, index
        sort(ans.begin(), ans.end());
        
        vector<int> res;
        
        for(int i=0; i<k; ++i) {
            res.push_back(ans[i].second);
        }
        
        return res;
    }
};