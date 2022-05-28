
bool isPossible(bool graph[101][101], int n, int node, vector<int> &col, int c)
{

    for (int j = 0; j < n; j++)
    {
        if (j != node && graph[j][node] == 1 && col[j] == c)
            return false;
    }
    return true;
}

bool func(bool graph[101][101], int m, int n, int i, vector<int> &col)
{

    if (i == n)
    {
        return true;
    }

    for (int k = 0; k < m; k++)
    {

        if (isPossible(graph, n, i, col, k))
        {

            col[i] = k;

            if (func(graph, m, n, i + 1, col))
                return true;

            col[i] = -1;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here

    vector<int> col(n, -1);

    return func(graph, m, n, 0, col);
}