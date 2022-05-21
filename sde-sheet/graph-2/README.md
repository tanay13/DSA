1. Dijkstra

   - Create a vector with all index valued INFINITY
   - Create a min heap priority queue and push (src,0) in it.
   - while pq.size() > 0 pop the top element and check if the prevDist + currDist > dist[it]
   - If yes then push in the pq and update the dist vector
   - return the dist vector

2. Bellman Ford

   - Used for directed graph where edges are negative
   - Used for detection of negative cycles
   - all the edges are relaxed V-1 times.
   - Dijkstra doesnt require relaxation of V-1 times because it processes nodes only once as it doesnt work on negative weights.
