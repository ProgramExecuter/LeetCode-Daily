class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size(), m = popped.size(), i = 0, j = 0;
        
        while(i < n  &&  j < m) {
            st.push(pushed[i]);
            
            // Check for 'stack' and 'popped' matching
            while(!st.empty()  &&  j < m  &&  st.top() == popped[j]) {
                st.pop();
                ++j;
            }
            
            ++i;
        }
        
        if(i == n  &&  j == m  &&  st.empty())
            return true;
        return false;
    }
};