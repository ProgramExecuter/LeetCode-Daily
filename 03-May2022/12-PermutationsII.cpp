// Time Complexity - O(N!)
// Space Complexity - O(1)

class Solution {
public:
    void util(vector<int>& nums, int idx, vector<vector<int>> &res) {
        int len = nums.size();
        
        if(idx == len) {                                    // We've reached end of array, store 'res'
            res.push_back(nums);
            return;
        }
        
        for(int i = idx; i < len; ++i) {
            if(i > idx  &&  nums[i] == nums[idx])            // If this is repetition of number, ignore it
                continue;
            
            swap(nums[i], nums[idx]);
            util(nums, idx + 1, res);
        }
        
        for(int i = len-1; i > idx; --i)                    // Get orback previous state of array
            swap(nums[i], nums[idx]);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());                     // Sort the array
        vector<vector<int>> res;
        
        util(nums, 0, res);
        
        return res;
    }
};