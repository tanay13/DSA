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
    TreeNode* invertTree(TreeNode* root) {
               
        
        if(root==NULL)
           return root;
        
       stack<TreeNode*> nodeStack;
       nodeStack.push(root);
        
        while(nodeStack.empty()==false)
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            
           
                
            swap(node->right,node->left);
            
            
            if(node->right)
            nodeStack.push(node->right);
            
            if(node->left)
            nodeStack.push(node->left);
            
            
            
                
            }      
        
        return root;
        
    }
};