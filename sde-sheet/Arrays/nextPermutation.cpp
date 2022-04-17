class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int ind1, ind2;
        for (ind1 = nums.size() - 2; ind1 >= 0; ind1--)
        {

            if (nums[ind1] < nums[ind1 + 1])
                break;
        }

        if (ind1 < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (ind2 = nums.size() - 1; ind2 > ind1; ind2--)
        {

            if (nums[ind1] < nums[ind2])
                break;
        }

        swap(nums[ind1], nums[ind2]);

        reverse(nums.begin() + ind1 + 1, nums.end());
    }
};