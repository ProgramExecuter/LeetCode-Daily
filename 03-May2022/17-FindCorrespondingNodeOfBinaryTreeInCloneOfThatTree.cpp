// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)                                                                       // Both lists ended
            return NULL;
        
        if(original == target)                                                              // If we found the target then return its respective 'cloned'
            return cloned;
        
        TreeNode* left  = getTargetCopy(original->left,  cloned->left,  target);            // If this isn't the 'target', then check in child nodes
        TreeNode* right = getTargetCopy(original->right, cloned->right, target);
        
        return left ? left : right;                                                         // Return whichever isn't NULL if there is a node !NULL
    }
};