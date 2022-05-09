// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN, n = nums.size();
        stack<int> st;
        
        for(int i = n-1; i >= 0; --i) {
            if(nums[i] < s3)                                // nums[i] becomes our S1, and we found 132
                return true;
            
            // Remove all numbers less than this one
            while(!st.empty()  &&  st.top() < nums[i]) {
                s3 = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};
