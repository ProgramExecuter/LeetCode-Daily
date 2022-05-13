///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;                             // Used for level order traversal
        if(root)    q.push(root);
        
        while( !q.empty() ) {
            Node* prev = NULL;                      // At start, prev = NULL, means we have no right node until now(recent right node = NULL)
            
            int len = q.size();
            for(int i = 0; i < len; ++i) {
                Node* curr = q.front();             // Get front node of queue
                q.pop();
                
                curr->next = prev;                  // Mark its 'next' with recent right node, and make it new recent right node
                prev = curr;
                
                if(curr->right)                     // Now finally, push new level's nodes in queue
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
        
        return root;
    }
};