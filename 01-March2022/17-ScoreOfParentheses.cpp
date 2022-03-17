class Solution {
public:
    int scoreOfParentheses(string s) {
        int l = 0, ans = 0;
        
        for(int i=0; i<s.size(); ++i) {
            // Going to inner or outer layer
            if(s[i] == '(')
                ++l;
            else
                --l;
            
            // We add the result of innermost '()' pair
            if(s[i] == ')'  &&  s[i-1] == '(')
                ans += 1<<l;
        }
        
        return ans;
    }
};