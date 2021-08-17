bool canJump(vector<int> &nums)
{
    int i = 0;
    for (int reach = 0; i < nums.size() && i <= reach; ++i)
        reach = max(i + nums[i], reach);
    return i == nums.size();
}

// if reach gets equal to or less than i then it means the jump is blocked
//and further indexes cannot be reached so we end the loop there and check the equality
//of reach and size of vector