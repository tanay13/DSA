class Solution
{
public:
    int firstOcc(int s, int e, char ch, vector<string> &p, int i)
    {
        int st = s;
        int en = e;

        while (st <= en && en < p.size())
        {
            int mid = st + (en - st) / 2;

            if (i > p[mid].length() - 1)
            {
                st = mid + 1;
            }
            else if ((mid == s || ch > p[mid - 1][i]) && p[mid][i] == ch)
                return mid;
            else if (p[mid][i] < ch)
            {
                st = mid + 1;
            }
            else
            {

                en = mid - 1;
            }
        }

        return -1;
    }

    int lastOcc(int s, int e, char ch, vector<string> &p, int i)
    {
        int st = s;
        int en = e;

        while (st <= en && en < p.size())
        {
            int mid = st + (en - st) / 2;

            if (i > p[mid].length() - 1)
            {
                st = mid + 1;
            }
            else if ((mid == e || ch < p[mid + 1][i]) && p[mid][i] == ch)
                return mid;
            else if (p[mid][i] > ch)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }

        return -1;
    }

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {

        vector<vector<string>> ans;

        sort(products.begin(), products.end());

        int s = 0, e = products.size() - 1;

        for (int i = 0; i < searchWord.length(); i++)
        {

            char ch = searchWord[i];

            int fo = firstOcc(s, e, ch, products, i);
            int lo = lastOcc(s, e, ch, products, i);

            if (fo == -1 || lo == -1)
            {

                int sz = ans.size();

                while (sz < searchWord.length())
                {
                    vector<string> v;
                    ans.push_back(v);
                    sz++;
                }

                return ans;
            }

            s = fo;
            e = lo;

            vector<string> v;

            for (int j = s; j <= e; j++)
            {
                if (j - s + 1 > 3)
                    break;
                v.push_back(products[j]);
            }

            ans.push_back(v);
        }

        return ans;
    }
};