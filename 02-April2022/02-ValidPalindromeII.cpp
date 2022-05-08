// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    bool isPalin(string s, int st, int en) {
        while(st < en) {
            if(s[st] != s[en])                      // Chars mismatch, not a palindrome
                return false;
            ++st;       --en;
        }
        
        return true;                                // String is palindrome
    }
    bool validPalindrome(string s) {
        int n = s.size();
        bool flag = true;
        
        if(n <= 2)  return true;
        
        int st = 0, en = n-1;
        
        while(st < en) {
            if(s[st] != s[en]) {
                // If remaining string becomes palindrome after removing "s[st]"
                bool remStart = isPalin(s, st+1, en);
                
                // If remaining string becomes palindrome after removing "s[st]"
                bool remEnd   = isPalin(s, st, en-1);
                
                if(remStart  ||  remEnd)        // If any of it is true, then return TRUE
                    return true;
                else
                    return false;
            }
            ++st;
            --en;
        }
        
        return true;
    }
};
