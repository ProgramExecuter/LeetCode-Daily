bool util(vector<int> a, vector<int> b) {
    int savingA = a[1]-a[0];
    int savingB = b[1]-b[0];
    
    if(savingA > savingB) {
        return true;
    }
    else if(savingA < savingB) {
        return false;
    }
    else {
        if(a[0] < b[0])
            return true;
        else
            return false;
    }
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), ans = 0;
        
        vector<vector<int>> cost;
        for(int i=0; i<n; ++i) {
            cost.push_back({costs[i][0], costs[i][1], i});
        }
        
        // Sort according to savings
        // saving = Cost saved by sending person to A rather than B
        sort(cost.begin(), cost.end(), util);
        
        for(int i=0; i<n; ++i) {
            if(i < n/2)                 // If the saving are high then send to city A
                ans += cost[i][0];
            else
                ans += cost[i][1];      // If the saving is low then send to city B
        }
        
        return ans;
    }
};