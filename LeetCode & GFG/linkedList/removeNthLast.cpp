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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *temp = head;

        int len = 0;

        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        ListNode *fp = head;
        ListNode *sp = head->next;
        int s = 1;

        if (len == 2)
        {
            if (n == 2)
                return sp;
        }

        if (len == 1)
            return NULL;

        while (s < len - n)
        {

            fp = fp->next;

            sp = sp->next;

            s++;
        }

        if (len - n == 0)
        {
            return sp;
        }

        fp->next = sp->next;

        return head;
    }
};