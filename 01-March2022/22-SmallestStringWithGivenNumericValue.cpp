class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        for(int i=1; i<=n; ++i) {
            // If remaining value of string can be fulfilled by remaining places
            // then add 'a' + 0
            // Else
            // add 'a' + something
            int reqAmount =  k-1 > 26*(n-i)  ?  k - 26*(n-i)  :  1;

            ans += ('a'+ reqAmount - 1);
            k -= reqAmount;
        }
        
        return ans;
    }
};