// Time Complexity - next() => O(H), hasNext() => O(1)
// Space Complexity - O(H)

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* tmp = root;
        
        while(tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }
    
    int next() {
        if(!hasNext())  return -1;
        
        TreeNode* tmp = st.top();
        int res = tmp->val;
        st.pop();
        
        tmp = tmp->right;       // Put right-node and all its left nodes
        while(tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */