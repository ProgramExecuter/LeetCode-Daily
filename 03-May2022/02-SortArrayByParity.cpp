// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, en = nums.size()-1;
        
        while(i < en) {
            if(nums[i]%2 == 1)                  // Move this 'odd' number to the back
                swap(nums[i], nums[en--]);      // Move back pointer
            else
                ++i;                            // Skip, it has right position
        }
        
        return nums;
    }
};