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
    void swapPair(ListNode *h1, ListNode *h2, ListNode *prev)
    {

        if (!h1 || !h2)
            return;

        h1->next = h2->next;
        h2->next = h1;
        prev->next = h2;

        if (!h1->next)
            return;

        swapPair(h1->next, h1->next->next, h1);

        return;
    }

    ListNode *swapPairs(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *ptr = head;

        ListNode *t = new ListNode();

        swapPair(ptr, ptr->next, t);

        return t->next;
    }
};