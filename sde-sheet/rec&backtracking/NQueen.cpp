class Solution
{
public:
    bool isValid(int i, int j, int n, vector<string> &b)
    {

        int i1 = i;
        int j1 = j;
        while (i1 < n && j1 < n)
        {

            if (b[i1][j1] == 'Q')
                return false;
            i1++;
            j1++;
        }
        i1 = i;
        j1 = j;
        while (i1 >= 0 && j1 >= 0)
        {

            if (b[i1][j1] == 'Q')
                return false;
            i1--;
            j1--;
        }
        i1 = i;
        j1 = j;
        while (i1 >= 0 && j1 < n)
        {
            if (b[i1][j1] == 'Q')
                return false;
            i1--;
            j1++;
        }
        i1 = i;
        j1 = j;
        while (i1 < n && j1 >= 0)
        {
            if (b[i1][j1] == 'Q')
                return false;
            i1++;
            j1--;
        }

        return true;
    }

    void backtrack(vector<string> &b, int i, map<pair<int, int>, int> &m, vector<int> &r, vector<int> &c,
                   vector<vector<string>> &ans)
    {

        if (i == b.size())
        {

            ans.push_back(b);
            return;
        }

        for (int j = 0; j < b.size(); j++)
        {

            if (r[i] == -1 && c[j] == -1 && isValid(i, j, b.size(), b))
            {
                r[i] = 1;
                c[j] = 1;
                b[i][j] = 'Q';
                backtrack(b, i + 1, m, r, c, ans);
                r[i] = -1;
                c[j] = -1;
                b[i][j] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;

        vector<string> b(n, "");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i] += '.';
            }
        }

        vector<int> r(n + 1, -1);
        vector<int> c(n + 1, -1);
        map<pair<int, int>, int> m;

        backtrack(b, 0, m, r, c, ans);

        return ans;
    }
};