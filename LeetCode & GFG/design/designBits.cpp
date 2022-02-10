class Bitset
{
public:
    string s;
    int flip1;
    int oneC;
    int zeroC;

    Bitset(int size)
    {

        zeroC = size;
        oneC = 0;
        flip1 = 0;
        for (int i = 0; i < size; i++)
            s += '0';
    }

    void fix(int idx)
    {

        if (flip1 % 2 != 0)
        {
            if (s[idx] == '1')
            {
                s[idx] = '0';
                oneC++;
                zeroC--;
            }
        }
        else
        {
            if (s[idx] == '0')
            {
                s[idx] = '1';
                oneC++;
                zeroC--;
            }
        }
    }

    void unfix(int idx)
    {

        if (flip1 % 2 != 0)
        {
            if (s[idx] == '0')
            {
                s[idx] = '1';
                oneC--;
                zeroC++;
            }
        }
        else
        {

            if (s[idx] == '1')
            {
                s[idx] = '0';
                oneC--;
                zeroC++;
            }
        }
    }

    void flip()
    {

        int temp = oneC;
        oneC = zeroC;
        zeroC = temp;
        flip1++;
    }

    bool all()
    {

        if (oneC == s.size())
            return true;
        return false;
    }

    bool one()
    {

        if (oneC >= 1)
            return true;
        return false;
    }

    int count()
    {

        return oneC;
    }

    string toString()
    {

        if (flip1 % 2 == 0)
            return s;

        string st = "";

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '0')
            {

                st += '1';
            }
            else
            {
                st += '0';
            }
        }
        return st;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */