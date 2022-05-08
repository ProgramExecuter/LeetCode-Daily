///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(NlogN)
// Space Complexity - O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());                 // Sort the array
        
        // Apply two-pointer approach
        int fr = 0, ba = nums.size()-1, res = 0;
        
        while(fr < ba) {
            if(nums[fr] + nums[ba]  ==  k) {
                ++res;                                  // Add it to result
                ++fr;   --ba;                           // Move 'front' and 'back'
            }
            else if(nums[fr] + nums[ba]  <  k) {
                ++fr;                                   // Move 'front', so that we can increase the sum
            }
            else {
                --ba;                                   // Move 'back', so that we can decrease the sum
            }
        }
        
        return res;
    }
};



///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        
        map<int, int> mp;               // Num - count map
        
        for(int num : nums) {
            int tar = k - num;          // Finding the 'tar'
            
            if(mp.find(tar) != mp.end()) {
                ++res;                  // We got a new pair
                --mp[tar];              // Increase frequency this 'tar'
                
                if(mp[tar] == 0)
                    mp.erase(tar);      // Remove 'tar' from map
            }
            else {
                ++mp[num];              // Increment its count
            }
        }
        
        return res;
    }
};
