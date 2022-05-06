///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(N * N)
// Space Complexity - O(1)

// Use two loops, to update the string in each loop




///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;      // Stores character and its count
        
        for(char ch : s) {
            char curr = ch;                     // Defaultly we push current character
            int cnt = 1;                        // It starting count = 1
            
            if(!st.empty() && ch == st.top().first) {
                curr = st.top().first;          // Push same 'char'
                cnt  = st.top().second + 1;     // Increase count
                
                st.pop();                       // Pop previous count
            }
            
            st.push({curr, cnt});
            
            if(st.top().second == k)            // count = k, delete from result
                st.pop();
        }
        
        string ans;
        while(!st.empty()) {
            // 'cnt' times 'character' is added to the string
            ans += string(st.top().second, st.top().first);
            
            st.pop();       // Pop the current character, as it has been added
        }
        reverse(ans.begin(), ans.end());        // We get reverse result due to stack, so 
                                                // reverse it again, to get it right
        
        return ans;
    }
};