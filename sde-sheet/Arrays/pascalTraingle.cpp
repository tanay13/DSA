class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> v;
        vector<int> vec;
        vec.push_back(1);
        v.push_back(vec);

        for (int i = 1; i < numRows; i++)
        {
            vector<int> vc;
            vc.push_back(v[i - 1][0]);

            for (int j = 0; j < v[i - 1].size() - 1; j++)
            {
                int el = v[i - 1][j] + v[i - 1][j + 1];
                vc.push_back(el);
            }

            vc.push_back(v[i - 1][v[i - 1].size() - 1]);
            v.push_back(vc);
        }

        return v;
    }
};