// Time Complexity - O(logN)
// Space Complexity - O(1)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        
        while(curr) {
            if(curr->val == val) {      // Found the node
                break;
            }
            else if(curr->val < val) {  // Search in right-subtree
                curr = curr->right;
            }
            else {
                curr = curr->left;      // Search in left-subtree
            }
        }
        
        return curr;
    }
}
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
 */;