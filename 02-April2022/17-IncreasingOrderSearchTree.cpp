// TIme Complexity - O(N)
// Space Complexity - O(H), at a time maximum space for stack ≈ height of BST

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        
        TreeNode *curr = root, *dummy = new TreeNode(0);
        TreeNode *tmp = dummy;
        
        while(curr  ||  !st.empty()) {
            while(curr) {           // Put this one's node's all subsequent left in stack
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();        // Get latest node from stack
            st.pop();
            
            curr->left = NULL;      // Make this node's left = NULL, after it is operated upon
            tmp->right = curr;      // Link the nodes
            
            tmp = tmp->right;       // Move right
            curr = curr->right;
        }
        
        return dummy->right;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */