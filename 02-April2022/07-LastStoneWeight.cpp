// Time Complexity - O(NlogN), inserting N elements in 'pq', each insertion takes O(logN)
// Space Complexity - O(N)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int ele : stones)   // Push all stones in priority queue
            pq.push(ele);
        
        int ans = 0;
        
        while(!pq.empty()) {
            int first = pq.top();
            pq.pop();
            
            if(pq.empty()) {    // If there's only one stone left, it's the result
                ans = first;
                break;
            }
            
            int second = pq.top();
            pq.pop();
            
            int rem = first - second;
            
            if(rem > 0)             // If a stone remains after smashing, then put it in 'pq'
                pq.push(rem);
        }
        
        return ans;
    }
};