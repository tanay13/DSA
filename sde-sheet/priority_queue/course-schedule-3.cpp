class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {

        if (courses.size() == 0)
            return 0;

        sort(courses.begin(), courses.end(), [](const vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int d = 0;

        priority_queue<int> p;

        for (auto it : courses)
        {
            d += it[0];
            p.push(it[0]);

            if (d > it[1])
            {
                d -= p.top();
                p.pop();
            }
        }

        return p.size();
    }
};