class Solution 
{
    public:
    
    bool bfsCycle(int el, vector<int> visited, vector<int> adj[])
    {
        queue<pair<int,int>> q;
        
        q.push({el,-1});
        visited[el] = 1;
        
        
        while(!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for(auto it: adj[node])
            {
                if(visited[it]==0)
                {
                 
                    q.push({it,node});
                    visited[it] = 1;
                }
                else if(it!= prev)
                    return true;
            }
        
        
        }
        return false;
        
        
    }
    
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V,0);
	    
	    for(int i = 0;i<V;i++)
	    {
	        if(!visited[i])
            {
                if(bfsCycle(i,visited,adj))
                    return true;
            }
	    }
	    
	    return false;
	    
	}
};