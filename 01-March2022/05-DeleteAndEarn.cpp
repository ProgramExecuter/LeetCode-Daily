class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> buckets(10001, 0);
        
        for (int num : nums) {
            buckets[num] += num;
        }
        
        vector<int> dp(10001, 0);
        dp[0] = buckets[0];
        dp[1] = buckets[1];
        
        for (int i = 2; i < buckets.size(); i++) {
            // Either add this bucket with prev's prev bucket
            // or take previous bucket
            dp[i] = max(buckets[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[10000];
    }
};