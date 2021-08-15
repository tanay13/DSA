class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {

        queue<int> q;

        q.push(start);

        vector<int> v(arr.size(), false);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node > arr.size() - 1 || node < 0 || v[node] == true)
                continue;

            // push the start+a[start] element in queue

            if (arr[node] == 0)
            {
                return true;
            }
            else
            {
                q.push(node + arr[node]);
                v[node] = true;
            }

            //push the start-a[start] element in queue
            if (arr[node] == 0)
            {
                return true;
            }
            else
            {
                q.push(node - arr[node]);
                v[node] = true;
            }
        }

        return false;
    }
};