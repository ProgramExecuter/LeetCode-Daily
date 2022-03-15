class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        vector<int> removingIdx;
        
        for(int i=0; i<s.size(); ++i) {
            char ch = s[i];
            
            if(ch == '(') {
                st.push({'(', i});
            }
            else if(ch == ')') {
                if(!st.empty())
                    st.pop();
                // Push it into 'removingIdx'
                // when its equivalent isn't present
                else
                    removingIdx.push_back(i);
            }
        }
          
        while(!st.empty()) {
            int idx = st.top().second;
            st.pop();
            // Push remaining idx into 'removingIdx'
            removingIdx.push_back(idx);
        }
        
        sort(removingIdx.begin(), removingIdx.end());
        
        int j = 0, lenRem = removingIdx.size();
        string ans;
        
        for(int i=0; i<s.size(); ++i) {
            // If this character is to be removed
            // from the result
            if(j < lenRem  &&  i == removingIdx[j])
                ++j;
            else
                ans += s[i];
        }
        
        return ans;
    }
};