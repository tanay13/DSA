class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int i = 0;

        while (i < nums.size())
        {

            if (nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1])
                {
                    return nums[i];
                }

                int t = nums[nums[i] - 1];

                nums[nums[i] - 1] = nums[i];

                nums[i] = t;
            }
            else
            {
                i++;
            }
        }

        return -1;
    }
};