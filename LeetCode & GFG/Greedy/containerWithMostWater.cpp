class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int s = 0;
        int e = height.size() - 1;
        int vol = INT_MIN;

        while (s < e)
        {

            int h = min(height[s], height[e]);

            vol = max(vol, h * (e - s));

            if (height[s] > height[e])
            {
                e--;
            }
            else
                s++;
        }

        return vol;
    }
};