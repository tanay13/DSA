/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftBound(TreeNode<int> *root, vector<int> &v)
{
    while (root)
    {
        if (root->left != NULL || root->right != NULL)
            v.push_back(root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}

void rightBound(TreeNode<int> *root, vector<int> &v)
{
    vector<int> temp;
    while (root)
    {
        if (root->left != NULL || root->right != NULL)
            temp.push_back(root->data);
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        v.push_back(temp[i]);
}

void leaf(TreeNode<int> *root, TreeNode<int> *orRoot, vector<int> &v)
{
    if (root == NULL)
        return;

    leaf(root->left, orRoot, v);
    if (root->right == NULL && root->left == NULL && root != orRoot)
        v.push_back(root->data);
    leaf(root->right, orRoot, v);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.

    vector<int> v;

    if (root == NULL)
        return v;

    v.push_back(root->data);

    if (root->left)
        leftBound(root->left, v);
    leaf(root, root, v);

    if (root->right)
        rightBound(root->right, v);

    return v;
}