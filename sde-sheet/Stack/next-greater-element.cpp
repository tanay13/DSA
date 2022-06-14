vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here

    vector<long long> ans;

    stack<long> s;

    int i = n - 1;

    while (i >= 0)
    {

        while (s.size() > 0 && s.top() < arr[i])
        {
            s.pop();
        }
        if (s.size() == 0)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }

        s.push(arr[i]);
        i--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}