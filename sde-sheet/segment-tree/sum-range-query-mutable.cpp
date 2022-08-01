class NumArray
{
public:
    int n;
    vector<int> segTree;

    void buildTree(vector<int> &arr, int l, int r, int ind)
    {
        // if we are at the leaf, we simply set the value at the given index
        if (l == r)
        {
            segTree[ind] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        // we build the left subtree and the right subtree
        buildTree(arr, l, mid, 2 * ind + 1);
        buildTree(arr, mid + 1, r, 2 * ind + 2);
        // value at this node will be equal to the sum of the value at its left and its right
        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    void update(int l, int r, int ind, int &i, int &x)
    {
        // we have reached the leaf node so we update the value at the leaf
        if (l == r)
        {
            segTree[ind] = x;
            return;
        }
        int mid = l + (r - l) / 2;
        // if the destination index is in the left subtree we update the left subtree else we update the right
        if (i <= mid)
        {
            update(l, mid, 2 * ind + 1, i, x);
        }
        else
        {
            update(mid + 1, r, 2 * ind + 2, i, x);
        }
        // update the current node after carrying out updations in its children
        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    int query(int l, int r, int ind, int &s, int &e)
    {
        // if the current range is completely inside the queried range, we return the complete ans
        if (l >= s && r <= e)
            return segTree[ind];
        // if the current range is completely outside, we return 0
        if (l > e || r < s)
            return 0;
        int mid = l + (r - l) / 2;
        // if there is a partial overlap, we get the answers from left and right subtrees and return the sum
        return query(l, mid, 2 * ind + 1, s, e) + query(mid + 1, r, 2 * ind + 2, s, e);
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segTree = vector<int>(4 * n);
        buildTree(nums, 0, n - 1, 0);
    }

    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(0, n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */