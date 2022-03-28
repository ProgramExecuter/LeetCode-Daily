class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] == target) {
                return true;
            }
            
            if( (nums[low] == nums[mid]) && 
                (nums[high] == nums[mid]) ) {       // Case where both sides seem same
                ++low;      --high;
            }
            else if(nums[mid] > target) {
                if(nums[mid] >= nums[low]) {   // 'Left'  is sorted
                    if(nums[low] <= target) {
                        high = mid-1;
                    }
                    else {
                        low = mid+1;
                    }
                }
                else {                          // 'Right' is sorted    
                    high = mid-1;
                }
            }
            else {
                if(nums[mid] >= nums[low]) {   // 'Left' is sorted
                    low = mid+1;
                }
                else {                          //  'Right' is sorted
                    if(target <= nums[high]) {
                        low = mid+1;
                    }
                    else {
                        high = mid-1;
                    }
                }
            }
        }
        
        return false;
    }
};