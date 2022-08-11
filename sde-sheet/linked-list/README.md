1. [Reverse linked list](https://leetcode.com/problems/reverse-linked-list/submissions/)

   - init dummy = NULL, h = head and n = head->next
   - since node will point to NULL when reversed. We point h->next = dummy
   - After this we shift each other by one place till the h node becomes NULL. At this point we return dummy var because it is pointing to the last node which becomes the new head in the reversed linked list

2. [Remove nth node from the end](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

   - Take the fast pointer to the nth node from the start.
   - maintain a slow pointer and prev pointer which is NULL initially
   - increament all the pointer till the fast pointer reaches the end
   - when the fast pointer reaches the end then it means that the slow pointer is at len-n index from the start ie nth node from the end.

3. [Reverse nodes in k groups](https://leetcode.com/problems/reverse-nodes-in-k-group/)

   - recursively reverse nodes for every k nodes
