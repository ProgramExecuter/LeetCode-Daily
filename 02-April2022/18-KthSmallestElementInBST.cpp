// Time Complexity - O(N)
// Space Complexity - O(H)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(curr  ||  !st.empty()) {
            while(curr) {                   // Push 'left' node in stack
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();                // Get top node from stack
            st.pop();
            
            --k;
            if(k == 0) {                    // This is k-th smallest element
                ans = curr->val;
                break;
            }
            
            curr = curr->right;             // Move to right sub-tree
        }
        
        return ans;
    }
};