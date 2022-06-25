class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {

        int mod = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i + 1] >= nums[i])
                continue;

            mod++;
            if (mod > 1)
                return false;

            if (i < 1 || nums[i - 1] <= nums[i + 1])
                nums[i] = nums[i + 1];
            else
                nums[i + 1] = nums[i];
        }

        return true;
    }
};