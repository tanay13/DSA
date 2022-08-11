class Solution
{
public:
    void reverse(ListNode *s, ListNode *e)
    {

        ListNode *p = NULL, *h = s, *nex = s->next;

        while (p != e)
        {
            h->next = p;
            p = h;
            h = nex;
            if (nex != NULL)
                nex = nex->next;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL || k <= 1)
            return head;

        ListNode *s = head, *e = head;

        int c = k - 1;

        while (c--)
        {
            e = e->next;
            if (e == NULL)
                return head;
        }

        ListNode *n = reverseKGroup(e->next, k);
        reverse(s, e);
        s->next = n;
        return e;
    }
};