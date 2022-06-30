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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL)
            return head;

        ListNode *d = NULL;
        ListNode *h = head;
        ListNode *n = head->next;
        int c = 0;
        while (h != NULL)
        {
            h->next = d;
            d = h;
            h = n;
            if (n != NULL)
                n = n->next;
            c++;
        }

        return d;
    }
};