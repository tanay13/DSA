class Solution
{
public:
    string addBinary(string a, string b)
    {

        int i = a.length() - 1;
        int j = b.length() - 1;

        string s = "";
        int carry = 0;

        while (i >= 0 || j >= 0)
        {

            int c = 0, d = 0;

            if (i >= 0)
            {
                c = a[i] - '0';
            }

            if (j >= 0)
            {
                d = b[j] - '0';
            }

            if (c != d)
            {
                if (carry == 0)
                    s += '1';
                else
                {
                    s += '0';
                    carry = 1;
                }
            }
            else if (c == d && c == 1)
            {
                if (carry == 0)
                {
                    s += '0';
                    carry = 1;
                }
                else
                {
                    s += '1';
                    carry = 1;
                }
            }
            else
            {
                if (carry == 0)
                {
                    s += '0';
                }
                else
                {
                    s += '1';
                    carry = 0;
                }
            }

            i--;
            j--;
        }

        if (carry == 1)
            s += '1';

        reverse(s.begin(), s.end());

        return s;
    }
};