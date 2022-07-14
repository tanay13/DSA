1. [Max path sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/)

   - Calculate the left and right subtree max sum and then add it to the node to find the path sum of the path passing through that particular node.

2. [Zig zag](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

   - Maintain a queue and initialize a vector with present size of queue and insert the nodes in the vector and simult. inserting the child of the nodes in the queue.

3. [Boundary Traversal](https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1)

   - left boundary + leaf nodes + right boundary

4. [Vertical View](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

5. [Top View](https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&=1)

6. [Bottom View](https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&=1)

7. [Right View](https://leetcode.com/problems/binary-tree-right-side-view/)

   - maintaining queue data structure
   - key: level , value: node->val
   - for right view enter the left node first

8. [Path to given Node](https://www.interviewbit.com/problems/path-to-given-node/)

9. [Max width](https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/)

   - Indexing all the nodes (left node -> 2*i+1 and right node -> 2*i+2);
   - to avoid overflow we start all the level's indexing with 0

10. [Construct Tree from preorder and inorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/)

    - Traverse the preorder order vector and create node for the current index.
    - Now search for the same element in the inorder vector.
    - All the element left to it will be on the left side of the particular element and similarly on the right side.
    - recursively create the nodes
