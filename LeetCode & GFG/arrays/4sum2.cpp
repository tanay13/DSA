class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {

        map<int, int> m, n;
        int c = 0;

        for (int i = 0; i < nums1.size(); i++)
        {

            for (int j = 0; j < nums2.size(); j++)
            {
                m[nums1[i] + nums2[j]]++;
            }
        }

        for (int k = 0; k < nums3.size(); k++)
        {
            for (int l = 0; l < nums4.size(); l++)
            {
                n[nums3[k] + nums4[l]]++;
            }
        }

        for (auto it : m)
        {

            if (n[-(it.first)] > 0)
            {

                c += n[-(it.first)] * it.second;
            }
        }

        return c;
    }
};