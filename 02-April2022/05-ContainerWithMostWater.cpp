// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        // Start from start, end index of heights
        int i = 0, j = n-1;
        
        // Width * Height
        int waterStored = (j - i) * min( height[i], height[j] );
        
        while(i < n   &&  j < n  &&  i < j) {
            if(height[i] < height[j])   // Move 'i'
                ++i;
            else                        // Move 'j'
                --j;
            
            int tmp = (j - i) * min(height[i], height[j]);
            waterStored = max(waterStored, tmp);
        }
        
        return waterStored;
    }
};