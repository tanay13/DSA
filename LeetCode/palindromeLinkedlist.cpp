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
    bool isPalindrome(ListNode* head) {
        
        deque<int> q;
        int count=0;
        while(head!=NULL)
        {
            q.push_back(head->val);
            
            count++;
            head = head->next;
        }
        
      while( q.front()==q.back() && q.size()>1 )
      {
          q.pop_front();
          q.pop_back();
      }
        
      if(q.size()==0 || q.size()==1)
          return true;
        else
            return false;
        
      
        
      
        
    }
};