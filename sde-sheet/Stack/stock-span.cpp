class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<pair<int, int>> s;
        vector<int> ans;
        int i = 0;

        while (i < n)
        {
            while (s.size() > 0 && s.top().first <= price[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                ans.push_back(i + 1);
            }
            else
            {

                int diff = i - s.top().second;
                ans.push_back(diff);
            }

            s.push({price[i], i});
            i++;
        }

        return ans;
    }
};