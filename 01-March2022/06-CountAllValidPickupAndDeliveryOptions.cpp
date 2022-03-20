class Solution {
public:
    int countOrders(int n) {
        long res = 1, mod = 1e9+7;
        
        // Permutations of places to be placed
        // for each order
        for(int i = 1; i <= n; ++i) {
            res *= (2*i - 1)*i;
            res %= mod;
        }
        
        return res;
    }
};