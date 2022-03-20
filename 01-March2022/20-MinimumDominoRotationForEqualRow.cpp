class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int face1 = tops[0], face2 = bottoms[0];
        int face1T = 1, face1B = 0, face2T = 0, face2B = 1;
        bool common1 = true, common2 = true;
        
        int n = tops.size();
        
        for(int i = 1; i < n; ++i) {
            // We have atleast one side as common
            if(
                (common1  &&  (tops[i] == face1  ||  bottoms[i] == face1))  ||
                (common2  &&  (tops[i] == face2  ||  bottoms[i] == face2))
            ) {
                // If 'face1' is common
                if(common1) {
                    if(tops[i] == face1)        ++face1T;
                    if(bottoms[i] == face1)     ++face1B;
                    
                    // This face1 isn't common anymore
                    if(tops[i] != face1  &&  bottoms[i] != face1)
                        common1 = false;
                }
                
                
                // If 'face2' is common
                if(common2) {
                    if(tops[i] == face2)        ++face2T;
                    if(bottoms[i] == face2)     ++face2B;
                    
                    // This face1 isn't common anymore
                    if(tops[i] != face2  &&  bottoms[i] != face2)
                        common2 = false;
                }
            }
            // Not possible, no face is common
            else {
                return -1;
            }
        }
        
        // No face is common
        if(!common1  &&  !common2)
            return -1;
        
        int ans = INT_MAX;
        
        if(common1) {
            // All top becomes 'face1'
            ans = min( ans, ( n - face1T ) );

            // All bottom becomes 'face1'
            ans = min( ans, ( n - face1B ) );
        }
        
        
        if(common2) {
            // All top becomes 'face2'
            ans = min( ans, ( n - face2T ) );

            // All bottom becomes 'face2'
            ans = min( ans, ( n - face2B ) );
        }
        
        return ans;
    }
};