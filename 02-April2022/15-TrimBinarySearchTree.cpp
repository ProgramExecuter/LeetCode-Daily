// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)   return NULL;
        
        
        if(root->val < low)                 // Below Range
            return trimBST(root->right, low, high);
        else if(root->val > high)           // Above Range
            return trimBST(root->left, low, high);
        
        
        root->left  = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
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