1. [Reverse linked list](https://leetcode.com/problems/reverse-linked-list/submissions/)

   - init dummy = NULL, h = head and n = head->next
   - since node will point to NULL when reversed. We point h->next = dummy
   - After this we shift each other by one place till the h node becomes NULL. At this point we return dummy var because it is pointing to the last node which becomes the new head in the reversed linked list
