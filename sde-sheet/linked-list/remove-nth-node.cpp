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

        if (head->next == NULL)
            return NULL;

        ListNode *prev = NULL, *slow = head, *fast = head;

        for (int i = 0; i < n - 1; i++)
            fast = fast->next;

        while (fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (prev != NULL)
            prev->next = slow->next;
        else
            head = slow->next;

        return head;
    }
};