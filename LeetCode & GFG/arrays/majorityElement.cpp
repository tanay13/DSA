//Moore voting algorithm

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int majorityEl = nums[0];
        int c = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (majorityEl == nums[i])
            {
                c++;
            }
            else
            {
                c--;
            }

            if (c == 0)
            {
                majorityEl = nums[i];
                c++;
            }
        }

        return majorityEl;
    }
};