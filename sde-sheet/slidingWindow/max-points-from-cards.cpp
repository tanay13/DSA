class Solution
{
public:
    int maxScore(vector<int> &c, int k)
    {

        int totalSum = 0;

        for (int it : c)
            totalSum += it;

        if (k == c.size())
            return totalSum;

        int i = 0, j = c.size() - k - 1;

        int currSum = 0;

        for (int k = i; k <= j; k++)
        {
            currSum += c[k];
        }

        int maxScore = INT_MIN;

        while (j < c.size())
        {
            int remSum = totalSum - currSum;
            maxScore = max(maxScore, remSum);
            currSum -= c[i];
            i++;
            j++;
            if (j < c.size())
                currSum += c[j];
        }

        return maxScore;
    }
};