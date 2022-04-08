class KthLargest
{
    int m;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {

        m = k;
        for (auto it : nums)
        {
            pq.push(it);
            if (pq.size() > m)
                pq.pop();
        }
    }

    int add(int val)
    {

        pq.push(val);

        if (pq.size() > m)
        {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */