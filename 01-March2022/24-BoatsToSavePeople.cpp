class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int st = 0, en = people.size()-1, ans = 0;
        
        while(st <= en) {
            if(st == en) {
                ++ans;
                break;
            }
            
            // We take people[en] on a boat, if people[st]
            // can also come in this, we take it
            
            // people[st] is taken on the same boat
            if(people[st]+people[en] <= limit) {
                ++st;
            }
            
            ++ans;
            --en;
        }
        
        return ans;
    }
};