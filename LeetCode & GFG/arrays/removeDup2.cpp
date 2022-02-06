class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int dup = 1;

        int start = 0;
        int end = 1;

        int n = nums.size();

        if (n < 2)
            return nums.size();

        while (end < nums.size())
        {

            if (nums[start] == nums[end])
            {
                dup++;

                if (dup > 2)
                {
                    vector<int>::iterator it;
                    it = nums.begin();

                    nums.erase(it + end);
                }
                else
                {
                    end++;
                }
            }
            else
            {
                dup = 1;
                start = end;
                end++;
            }
        }

        return nums.size();
    }
};