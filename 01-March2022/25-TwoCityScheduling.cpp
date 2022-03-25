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
        
        // Sort according to savings
        // saving = Cost saved by sending person to A rather than B
        sort(costs.begin(), costs.end(), util);
        
        for(int i=0; i<n; ++i) {
            if(i < n/2)                 // If the saving are high then send to city A
                ans += costs[i][0];
            else
                ans += costs[i][1];      // If the saving is low then send to city B
        }
        
        return ans;
    }
};