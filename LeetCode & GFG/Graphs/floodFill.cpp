// Recursive DFS approach

class Solution
{
public:
    void dfs(int i, int j, int m, int n, int **visited, vector<vector<int>> &image, int prevStart, int newColor)
    {

        if ((i < 0 || i >= m) || (j < 0 || j >= n))
            return;

        if (visited[i][j] == 1)
            return;

        visited[i][j] = 1;

        if (image[i][j] != prevStart || image[i][j] == newColor)
            return;
        else
            image[i][j] = newColor;

        dfs(i, j - 1, m, n, visited, image, prevStart, newColor);
        dfs(i, j + 1, m, n, visited, image, prevStart, newColor);
        dfs(i - 1, j, m, n, visited, image, prevStart, newColor);
        dfs(i + 1, j, m, n, visited, image, prevStart, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        int **visited;

        int m = image.size();
        int n = image[0].size();

        visited = new int *[m + 1];

        for (int i = 0; i < m + 1; i++)
        {
            visited[i] = new int[n + 1];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;
        }

        int prevStart = image[sr][sc];

        dfs(sr, sc, m, n, visited, image, prevStart, newColor);

        return image;
    }
};