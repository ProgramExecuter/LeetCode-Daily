// Time Complexity - O(N*N)
// Space Complexity - O(N*N)

class Solution {
public:
    void getAdjacency(vector<vector<int>>& times, vector<vector<pair<int, int>>> &adj) {
        for(auto link : times) {
            adj[link[0]].push_back({link[1], link[2]});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        getAdjacency(times, adj);
        
        vector<int> time(n+1, INT_MAX);
        time[0] = time[k] = 0;
        
        queue<int> q;
        q.push(k);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(pair<int, int> nB : adj[curr]) {
                int currNum  = nB.first;
                int currTime = time[curr] + nB.second;

                if(currTime < time[currNum]) {	// We found shorter distance
                    time[currNum] = currTime;
                    q.push(currNum);
                }
            }
        }
        
        int ans = 0;
        for(int x : time) {
            if(x == INT_MAX)    return -1;
            ans = max(ans, x);
        }
        
        return ans;
    }
};