class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int l = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (l > prices[i])
                l = prices[i];
            if (l < prices[i])
            {
                profit = max(profit, prices[i] - l);
            }
        }

        return profit;
    }
};