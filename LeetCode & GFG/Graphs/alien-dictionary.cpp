public:
void toposort(int node, vector<int> &visited, vector<char> &vec, vector<int> graph[])
{

    visited[node] = 1;

    for (auto it : graph[node])
    {
        if (visited[it] == -1)
            toposort(it, visited, vec, graph);
    }

    vec.push_back(node + 'a');
}

string findOrder(string dict[], int N, int K)
{
    //code here

    vector<int> graph[K];

    for (int i = 0; i < N - 1; i++)
    {

        string s1 = dict[i];
        string s2 = dict[i + 1];

        for (int j = 0; j < min(s1.length(), s2.length()); j++)
        {
            if (s1[j] != s2[j])
            {
                graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> visited(K, -1);
    vector<char> vec;
    for (int i = 0; i < K; i++)
    {
        if (visited[i] == -1)
            toposort(i, visited, vec, graph);
    }

    string s = " ";

    for (int i = K - 1; i >= 0; i--)
    {
        s += vec[i];
    }

    return s;
}