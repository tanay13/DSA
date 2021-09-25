vector<int> Solution::dNums(vector<int> &A, int B)
{

    unordered_map<int, int> map;

    for (int i = 0; i < B; i++)
    {
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = 1;
        }
        else
            map[A[i]]++;
    }
    vector<int> ans;
    int count = map.size();
    int start = 0;
    ans.push_back(count);

    for (int i = B; i < A.size(); i++)
    {

        map[A[start]] -= 1;
        if (map[A[start]] == 0)
        {
            count--;
        }
        start++;

        if (map.find(A[i]) == map.end() || map[A[i]] == 0)
        {
            map[A[i]] = 1;
            count++;
        }
        else
        {
            map[A[i]]++;
        }

        ans.push_back(count);
    }

    return ans;
}
