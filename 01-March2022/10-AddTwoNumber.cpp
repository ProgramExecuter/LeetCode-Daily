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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode *dummy = new ListNode(0);
        ListNode* tmp = dummy;
        
        while(l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            
            int sum = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            
            if(l1 == NULL) {
                // Make this node of addition
                l2->val = sum;
                tmp->next = l2;
                ListNode* nxt = l2->next;
                
                // Clear its next path
                tmp->next->next = NULL;
                l2 = nxt;
            }
            else {
                // Make this node of addition
                l1->val = sum;
                tmp->next = l1;
                ListNode* nxt = l1->next;
                
                // Clear its next path
                tmp->next->next = NULL;
                l1 = nxt;
                
                if(l2 != NULL)
                    l2 = l2->next;
            }
            
            tmp = tmp->next;
        }
        
        if(carry > 0) {
            ListNode* last = new ListNode(carry);
            tmp->next = last;
        }
        
        return dummy->next;
    }
};