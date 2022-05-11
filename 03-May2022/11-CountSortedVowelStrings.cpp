///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);               // It contains strings made by {'a', 'e', 'i', 'o', 'u'} as starting character
        
        for(int i = 2; i <= n; ++i) {       // Loop for n=2 or more
            int sum = 0;
            
            for(int j = 4; j >= 0; --j) {   // dp[j] = sum_from_back
                sum += dp[j];
                
                dp[j] = sum;
            }
        }
        
        int res;
        for(int x : dp)     res += x;       // Total number of strings made = sum of all 'dp'
        
        return res;
    }
};




///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution {
public:
    int countVowelStrings(int n) {
        // Using permutation and combination
        // nCr = ( n! ) / ( r! * (n-r)! )
        //
        // So, here (n+4) C 4  =>  ( (n+4)! ) / ( n! * 4! )   =>  (n+4)*(n+3)*(n+2)*(n+1) / 24
        // We choose 4 letters since 1 is fixed
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};