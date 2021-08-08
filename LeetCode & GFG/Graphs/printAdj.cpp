vector<vector<int>>printGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<vector<int>> graph;
	    
	    for(int i=0;i<V;i++)
	    {
	        vector<int> v;
	        v.push_back(i);
            for(int j=0;j<adj[i].size();j++)
            {
                v.push_back(adj[i][j]);
            }
            graph.push_back(v);
	    }
	    
	    return graph;
}