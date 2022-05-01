1. [Clone graph](https://leetcode.com/problems/clone-graph/)

- Create a map to keep track of all created node
- loop through the node's neighbour and push it in the newly created similar node using recursive dfs call
- base condition - if a node is already present in the map then it has already started or completed its process of adding the neighbours so just return that node

2. [Course Schedule - cycle in directed graph](https://leetcode.com/problems/course-schedule/submissions/)
   - Checking if the node comes again in its own dfs call
   - maintain two vectors... one for visited nodes and other for dfs call
