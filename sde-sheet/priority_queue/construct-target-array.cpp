class Solution
{
public:
    bool isPossible(vector<int> &target)
    {

        if (target.size() == 1)
            return target[0] == 1;

        priority_queue<int> pq;
        long long sum = 0;
        for (int it : target)
        {
            pq.push(it);
            sum += it;
        }
        while (pq.top() != 1)
        {

            int n = pq.top();
            pq.pop();
            int v = n % (sum - n);

            if (sum - n == 1)
                return true;

            if (v == n || v == 0)
                return false;
            pq.push(v);
            sum = sum - (n - v);
        }

        return true;
    }
};