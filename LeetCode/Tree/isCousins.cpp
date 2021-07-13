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
    int depthX=-1,depthY=-2;
    TreeNode* rootX=NULL,*rootY=NULL;
    bool foundX = false;
    bool foundY = false;
    bool isCousins(TreeNode* root, int x, int y) {
        
        
        depth(root,NULL,x,y,0);
        
    
        if(depthX==depthY)
        {
            if((rootX->val)!=(rootY->val))
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    
    void depth(TreeNode* root,TreeNode* parent,int x,int y,int d)
    {
        if(root==NULL)
            return ;
        
        if(root->val==x)
        {
            rootX = parent; 
            foundX = true;
            depthX = d;
            return ;
        }
        else if(root->val==y)
        {
            rootY = parent;
            foundY = true; 
            depthY = d;
            return;
        }
        
        
        
        if(!foundX || !foundY)
        {
           depth(root->left,root,x,y,d+1);
            
        }
        if(!foundX || !foundY)
        {
            depth(root->right,root,x,y,d+1);
            
        }
    
        
        return;
        
        
    }
};