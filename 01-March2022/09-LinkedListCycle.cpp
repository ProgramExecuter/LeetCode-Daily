/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // If the list has 0 or 1 node only
        if(head == NULL  ||  head->next == NULL)
            return false;
        
        ListNode *slow = head, *fast = head;
        
        while(fast  &&  fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If these pointers meet then there's a cycle
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};