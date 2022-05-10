class Solution {
public:
    void util(int &k, int n, vector<int> &curr, vector<vector<int>> &res) {
        if(curr.size() == k  &&  n == 0) {          // Found one of the result
            res.push_back(curr);
            return;
        }
        
        int st = !curr.size() ? 1 : curr.back()+1;  // If 'curr' is empty, then start from '1' else start from 'last inserted num + 1'
        
        for(int i = st; i <= 9; ++i) {
            if(n-i < 0)     break;                  // Adding this number exceeds required sum
            
            curr.push_back(i);
            util(k, n-i, curr, res);
            
            curr.pop_back();                        // Backtracking
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        
        util(k, n, curr, res);
        
        return res;
    }
};