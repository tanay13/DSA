class Solution
{
public:
    int compareVersion(string version1, string version2)
    {

        int i = 0;
        int j = 0;

        int n = version1.length();
        int m = version2.length();

        int sz = min(m, n);

        string s = "0";
        string k = "0";

        while (i < n || j < m)
        {

            while (i < n)
            {
                if (version1[i] == '.')
                {

                    break;
                }
                s += version1[i];

                i++;
            }

            while (j < m)
            {
                if (version2[j] == '.')
                {

                    break;
                }
                k += version2[j];
                j++;
            }

            if (stoi(s) > stoi(k))
            {
                return 1;
            }
            else if (stoi(s) < stoi(k))
                return -1;

            s = "0";
            k = "0";

            i++;
            j++;
        }

        return 0;
    }
};