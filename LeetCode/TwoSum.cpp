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
        
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* head = new ListNode(0);
        ListNode * result = head;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        int carry = 0;
        int x=0,y=0;
        while(a!=NULL || b!=NULL)
        {
           if(a!=NULL)
             {
               x = a->val;
              }
            else
                x = 0;
            
            if(b!=NULL)
            {
                y = b->val;
            }
            else
                y = 0;
           int sum = x + y + carry;
           int digit = sum%10;
           result->next = new ListNode(digit) ;
           result = result->next;
           carry = sum/10;
        
        if(a!=NULL)
            a = a->next;
        if(b!=NULL)
            b = b->next;
           
           
            
        }
        
        if(carry == 1)
        {
            result->next = new ListNode(1);
        }
        
        return head->next;
        
        
        
    }
};