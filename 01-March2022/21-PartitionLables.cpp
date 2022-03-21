class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> charFL;
        int n = s.size();
        
        // Find first and last occurence of each character
        for(int i=0; i<n; ++i) {
            char ch = s[i];
            
            // If this is first occurence of this character
            if(charFL.find(ch) == charFL.end())
                charFL[ch] = {i, i};
            // If this character has appeared before
            else
                charFL[ch].second = i;
        }
        
        vector<int> ans;
        int st = 0, en = 0, i = 0;
        
        while(i < n) {
            char ch = s[i];
            
            // New ending index of current partition
            en = max(en, charFL[ch].second);
            
            // We have reached end of current partition
            if(i == en) {
                ans.push_back(en-st+1); // Push this partition size to result
                st = en + 1;
                en = st;
            }
            
            ++i;
        }
        
        return ans;
    }
};