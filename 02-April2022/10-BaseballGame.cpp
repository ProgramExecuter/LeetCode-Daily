class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int num1, num2;
        
        for(string currOp : ops) {
            // Add 'num' = previous two score's sum
            if(currOp[0] == '+') {
                // Get recent two nums
                num1 = st.top();        st.pop();
                num2 = st.top();
                
                // Push the numbers
                st.push(num1);      st.push(num1 + num2);
            }
            // Add 'num' with Double the previous score
            else if(currOp[0] == 'D') {                 
                num1 = st.top();
                
                st.push(num1 * 2);
            }
            else if(currOp[0] == 'C') {                 // Remove the last score
                st.pop();
            }
            else {                                      // Add this number
                num1 = stoi(currOp);                    // Convert string to int, using stoi()
                st.push(num1);
            }
        }
        
        int ans = 0;
        
        while(!st.empty()) {                            // Add all the numbers in stack
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};