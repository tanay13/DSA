class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int leftGas = 0;
        int index = 0;
        int need = 0;

        for (int i = 0; i < cost.size(); i++)
        {

            leftGas += gas[i] - cost[i];

            if (leftGas < 0)
            {
                need += abs(leftGas);
                leftGas = 0;
                index = i + 1;
                if (i + 1 > cost.size() - 1)
                    return -1;
                continue;
            }
            else if (i == cost.size() - 1 && leftGas < need)
            {
                return -1;
            }
        }

        return index;
    }
};