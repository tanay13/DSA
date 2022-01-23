class Solution
{
public:
    int makeSeq(int num)
    {

        string s = to_string(num);

        int a = s[0] - '0';

        string s1 = "";
        s1 += s[0];

        for (int i = 1; i < s.length(); i++)
        {

            int b = a + 1;

            if (b > 9)
                return -1;

            a = b;

            s1 += to_string(b);
        }
        return stoi(s1);
    }

    vector<int> sequentialDigits(int low, int high)
    {

        vector<int> ans;

        int i = low;

        while (i <= high)
        {

            int a = makeSeq(i);

            if (a != -1)
            {
                if (a <= high && a >= low)
                    ans.push_back(a);
            }

            int b = log10(i);

            int c = pow(10, b);

            i += c;
        }

        return ans;
    }
};