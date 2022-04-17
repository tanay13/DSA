class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int z = 0, o = 0, t = 0;

        for (auto i : nums)
        {
            if (i == 0)
                z++;
            else if (i == 1)
                o++;
            else
                t++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (z > 0)
            {
                nums[i] = 0;
                z--;
            }
            else if (o > 0)
            {
                nums[i] = 1;
                o--;
            }
            else if (t > 0)
            {
                nums[i] = 2;
                t--;
            }
        }
    }
};