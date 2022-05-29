1. [Clone graph](https://leetcode.com/problems/clone-graph/)

- Create a map to keep track of all created node
- loop through the node's neighbour and push it in the newly created similar node using recursive dfs call
- base condition - if a node is already present in the map then it has already started or completed its process of adding the neighbours so just return that node

2. [Course Schedule - cycle in directed graph](https://leetcode.com/problems/course-schedule/submissions/)

   - Checking if the node comes again in its own dfs call
   - maintain two vectors... one for visited nodes and other for dfs call

3. [toposort DFS](https://practice.geeksforgeeks.org/problems/topological-sort/1#)

   - Push the node in the stack when its DFS call is over
   - this will ensure that it comes before all its connected vertices

4. [Toposort BFS]

   - If indegree is 0 push in the q and perform bfs and keep decreasing indgree

5. [Number of island](https://leetcode.com/problems/number-of-islands/submissions/)

   - Start from the first cell which is 1 and traverse using dfs/bfs and visit all connected 1s.
   - After the dfs is completed increament the island-counter by 1

6. [Most stones removed](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

   - Construct an undirected graph of stones with same row or column
   - Do DFS to know how many nodes can be reached
