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
    vector<int> preorderTraversal(TreeNode* root) {
        
       vector<int> preorder;
       if(root==NULL)
           return preorder;
        
       stack<TreeNode*> nodeStack;
       nodeStack.push(root);
        
        while(nodeStack.empty()==false)
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            preorder.push_back(node->val);
            
            if(node->right)
            {
                nodeStack.push(node->right);
        
            }
            
              if(node->left)
            {
                nodeStack.push(node->left);
        
            }
            
        }
        
        return preorder;
            
        
    }
};