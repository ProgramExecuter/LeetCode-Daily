/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If there are <= 1 nodes, then return
        if(head == NULL  ||  head->next == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* dum = dummy;
        
        // Stop loop when, no.of nodes left <= 1
        while(dum  &&  dum->next  &&  dum->next->next) {
            
            // This value has duplicates in this list
            if(dum->next->val == dum->next->next->val) {
                ListNode* tmp = dum->next->next;
                
                // Delete all nodes of 'this' value except for 'ONE'
                while((tmp != NULL)  &&  (tmp->val == dum->next->val)) {
                    ListNode *del = tmp, *nxt = tmp->next;
                    dum->next->next = tmp->next;
                    delete del;
                    tmp = nxt;
                }
                
                // Delete that 'ONE' left
                ListNode* del = dum->next;
                dum->next = dum->next->next;
                delete del;
                
                // We are already at next node, since we deleted the dupicate nodes
                continue;
            }
            
            dum = dum->next;
        }
        
        return dummy->next;
    }
};