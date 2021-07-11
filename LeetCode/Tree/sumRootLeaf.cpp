/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        
        return sum(root,0); 
        
    }
    
    int sum(TreeNode* root,int val)
    {
        if(!root){
            return ans;
        }
        
        val = val*10;
        val = val+root->val;
        
        if(!root->left && !root->right)
        {
            return ans+=val;
        }
        
        sum(root->left,val);
        sum(root->right,val);
        
        return ans;
    }
};