class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {

        for (int i = 0; i < flowerbed.size(); i++)
        {

            if (i - 1 < 0 && i + 1 < flowerbed.size())
            {

                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i + 1 > flowerbed.size() - 1 && i - 1 >= 0)
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i - 1 < 0 && i + 1 > flowerbed.size() - 1)
            {
                if (flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        if (n <= 0)
            return true;
        else
            return false;
    }
};