// Time Complexity - O(NlogN)
// Space Complexity - O(1)

class Solution {
public:
    bool canMakeSubarray(vector<int> &nums, int target, int m) {
        int curr = 0;
        
        for(int ele : nums) {
            if(curr+ele <= target) {
                curr += ele;
            }
            else {
                if(ele > target)    // Single element > target, so this subarray isn't possible
                    return false;
                --m;
                curr = ele;
            }
        }
        if(curr <= target)   --m;
        
        if(m >= 0)  return true;            // m splits or more can be made
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = INT_MIN, high = 0;
        
        for(int i : nums) {         // Lowest value of a subsequence is MIN(array)
            low = max(i, low);      // Highest value of a subsequence is SUM(array)
            high += i;
        }
        
        while(low < high) {
            int mid = low + (high-low)/2;
                
            if(canMakeSubarray(nums, mid, m))   // This sum's subsequence can be made, so try lower sum
                high = mid;
            else                    // This cannot be done, try higher sum
                low = mid+1;
        }
        
        return low;
    }
};