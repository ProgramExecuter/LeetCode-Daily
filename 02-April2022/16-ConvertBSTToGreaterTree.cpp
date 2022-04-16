// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int util(TreeNode* root, int adNum) {
        if(!root)   return 0;
        
        int tmp = root->val;                                // Save node's value temporarily
        
        int right = util(root->right, adNum);               // Get right sub-tree's sum
        
        int left  = util(root->left, right + tmp + adNum);  // Get left sub-tree sum
        
        root->val += adNum + right;                         // Update this node's value
        
        return (tmp + left + right);                        // Return sum of this whole sub-tree
    }
    TreeNode* convertBST(TreeNode* root) {
        util(root, 0);
        
        return root;
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