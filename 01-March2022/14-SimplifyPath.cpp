class Solution {
public:
    string simplifyPath(string path) {
        path += '/';  // To complete the last file_name path
        
        int n = path.size();
        
        vector<string> tmp;
        string curr;
        
        for(int i=0; i<n; ++i) {
            if(path[i] == '/') {
                if(curr.size() == 0  ||  curr.compare(".") == 0) {
                    ;
                }
                // Go back a folder if string == ".."
                else if(curr.compare("..") == 0) {
                    if(tmp.size() > 0)
                        tmp.pop_back();
                }
                // Push the file_name to vector
                else {
                    tmp.push_back(curr);
                }
                
                curr = "";  // Empty current string
            }
            else {
                curr += path[i];
            }
        }
        
        string ans;

        for(string s : tmp)     // Create 'canonical path'
            ans += '/' + s;
        
        if(ans.size() == 0)     // If string is empty then make it '/'
            ans += '/';
        
        return ans;
    }
};