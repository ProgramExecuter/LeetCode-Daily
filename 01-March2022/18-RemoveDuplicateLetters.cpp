class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> vis(26, false);
        
        // Store cnt of each character
        for(char ch : s)
            ++cnt[ ch-'a' ];
        
        string ans = "";
        for(int i=0; i<s.size(); ++i) {
            // Decrease count of characters remaining to be analysed
            --cnt[ s[i]-'a' ];
            
            // If this character is already added to 'ans'
            // then skip it
            if(vis[ s[i]-'a' ] == true)
                continue;
            
            
            // If current character is smaller than last character in stack
            // which occurs later in the string again
            // it can be removed for now and added later 
            while(
                ans.size() > 0  &&  
                ans.back() > s[i]  &&  
                cnt[ ans.back()-'a' ] > 0
            ) {
                vis[ ans.back()-'a' ] = false;
                ans.pop_back();
            }

            // Add this character to the 'ans'
            ans += s[i];
            vis[ s[i]-'a' ] = true;
        }
        
        return ans;
    }
};