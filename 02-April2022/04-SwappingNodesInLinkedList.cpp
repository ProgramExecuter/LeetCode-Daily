// Time Complexity - O(N + N)
// Space Complexity - O(1)

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        
        // Find first node
        while(--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        // Find second node
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        swap(ptr2->val, kth->val);
        
        return head;
    }
    
    // You can swap nodes as well
    // But we will have to take previous of both swapping nodes
    // We will also need to keep in mind the edge cases
    // Edge Cases -> n == k, k == 1
};
