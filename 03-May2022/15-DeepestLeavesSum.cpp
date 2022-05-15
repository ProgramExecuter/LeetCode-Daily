// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;                                        // This stores our result
        
        queue<TreeNode*> q;                                 // Used for level-order traversal
        if(root)    q.push(root);
        
        while(!q.empty()) {
            int len = q.size();                             // Take no. of nodes of this level
            
            ans = 0;                                        // Override the previous level result, if this level exists
                                                            // Because currently this level is the lowest level
            
            for(int i = 0; i < len; ++i) {
                TreeNode* curr = q.front();                 // Take current node, from front of queue
                q.pop();
                
                ans += curr->val;                           // Add the values of nodes of this level
                
                if(curr->left)  q.push(curr->left);         // Push curr's child nodes into queue
                if(curr->right) q.push(curr->right);
            }
        }
        
        return ans;
    }
};