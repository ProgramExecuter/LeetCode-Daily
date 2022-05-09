// Time Complexity - O(N)
// Space Complexity - O(N) => for 'cnt' array

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans = 0, mod = 1000000007;
        
        vector<int> cnt(101, 0);        // Store count of each element
        for(int i : arr)
            ++cnt[i];
        
        for(int i=0; i<=100; ++i) {
            for(int j=i; j<=100; ++j) {
                int k = target-i-j;
                
                if(k < 0  ||  k > 100)
                    continue;
                
                // All elements are same
                // thus by combination  nC3  =  n*(n-1)*(n-2)/6
                if(i == j  &&  j == k) {
                    ans += ( ( 1ll*(cnt[i])*(cnt[i]-1)*(cnt[i]-2) ) / 6 );
                }
                // Two elements are same, thus by P&C
                // (n*(n-1)/2) * x
                else if(i == j  &&  j != k) {
                    ans += 1ll*( ( ( 1ll*(cnt[i])*(cnt[i]-1) ) / 2 ) * (cnt[k]) );
                }
                // All elements are different
                // thus cnt[i] * cnt[j] * cnt[k]
                else if(i < j  &&  j < k) {
                    ans += ( 1ll * cnt[i] * cnt[j] * cnt[k] );
                }
                
                ans %= mod;
            }
        }
        
        return int(ans);
    }
};
