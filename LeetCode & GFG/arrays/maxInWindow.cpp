vector<int> ans;
deque<int> dq;

for (int i = 0; i < nums.size(); i++)
{
    //removing out of bound elements
    while (!dq.empty() && dq.front() == i - k)
    {
        dq.pop_front();
    }

    //removing elements which are smaller than current element
    while (!dq.empty() && nums[dq.back()] < nums[i])
    {
        dq.pop_back();
    }

    dq.push_back(i);

    //pushing the greatest element in the current window into the ans vector
    if (i >= k - 1)
    {
        ans.push_back(nums[dq.front()]);
    }
}
return ans;