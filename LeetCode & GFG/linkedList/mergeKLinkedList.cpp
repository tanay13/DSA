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
    ListNode *merge(ListNode *list1, ListNode *list2)
    {

        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = new ListNode();

        ListNode *tmp = head;

        while (list1 && list2)
        {

            if (list1->val < list2->val)
            {

                tmp->next = list1;
                list1 = list1->next;
            }
            else
            {

                tmp->next = list2;
                list2 = list2->next;
            }

            tmp = tmp->next;
        }
        if (list1)
            tmp->next = list1;
        if (list2)
            tmp->next = list2;

        return head->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;

        ListNode *l1 = lists[0];

        ListNode *res = l1;

        for (int i = 1; i < lists.size(); i++)
        {

            res = merge(res, lists[i]);
        }

        return res;
    }
};