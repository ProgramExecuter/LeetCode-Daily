class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lenArr = nums.size();
        
        int startIdx = 0;
        int endIdx = lenArr-1;
        
        while(startIdx <= endIdx)
        {
            int midIdx = (startIdx + endIdx) / 2;
            
            if( nums[midIdx] < target )         // move to right-side
                startIdx = midIdx + 1;
            else if( nums[midIdx] > target )    // move to left-side
                endIdx = midIdx - 1;
            else                                // Found element
                return midIdx;
        }
        
        // If element not found
        return -1;
    }
};