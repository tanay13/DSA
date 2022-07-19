class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {

        vector<vector<int>> sum(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix[0].size(); i++)
        {
            int s = 0;
            for (int j = 0; j < matrix.size(); j++)
            {

                s += matrix[j][i];
                sum[j][i] = s;
            }
        }

        int c = 0;

        for (int i = 0; i < matrix.size(); i++)
        {

            for (int j = i; j < matrix.size(); j++)
            {

                int s = 0;

                map<int, int> m;
                m[0] = 1;

                for (int p = 0; p < matrix[0].size(); p++)
                {
                    s += (sum[j][p] - sum[i][p] + matrix[i][p]);

                    if (m.find(s - target) != m.end())
                    {

                        c += m[s - target];
                    }

                    m[s]++;
                }
            }
        }

        return c;
    }
};