class Solution
{
public:
    int furthestBuilding(vector<int> &h, int bricks, int ladders)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < h.size() - 1; i++)
        {
            int j = h[i + 1] - h[i];
            if (j > 0)
            {
                if (pq.size() < ladders)
                {
                    pq.push(j);
                    continue;
                }
                if (pq.size() > 0 && pq.top() < j)
                {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(j);
                }
                else
                {
                    bricks -= j;
                }

                if (bricks < 0)
                    return i;
            }
        }

        return h.size() - 1;
    }
};