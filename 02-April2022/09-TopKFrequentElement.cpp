// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> cntEle;
        
        for(int i : nums)                           // Find frequency of each element
            ++cntEle[i];
        
        vector<vector<int>> bucket(n+1, vector<int>());
        
        for(auto itr : cntEle)
            bucket[itr.second] . push_back(itr.first);  // Saving cnt -> num, pairs
        
        
        vector<int> res;
        
        for(int idx = n; idx >= 0; --idx) {
            if(k == 0)  break;                      // Found k elements, thus BREAK
            
            for(int ele : bucket[idx]) {
                if(k == 0)  break;
                res.push_back(ele);
                --k;
            }
        }
        xy:
        
        return res;
    }
};