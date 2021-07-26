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

// In this question passing unordered_map by ref is necessary because it gives time advantage (as variables are not copied to another variables) 


class Solution {
public:
    int index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> inord;
         
        for(int i=0;i<inorder.size();i++)
        {
            inord[inorder[i]] = i;
            
        }
        
        
        
        int end = preorder.size()-1;
        
        int start = 0;

        
        
        return buildFullTree(preorder,inord,start,end);
       
        
    }
    
    TreeNode* buildFullTree(vector<int> preorder,unordered_map<int,int>& inord,int start,int end)
    {
        
        
        if(start>end)
        {
            return NULL;
        }
        
        
       
        int curr = preorder[index++];
        TreeNode* node = new TreeNode(curr);
    
        
        int Currindex = inord[curr];
        
       
        
        node->left = buildFullTree(preorder,inord,start,Currindex-1);
        node->right = buildFullTree(preorder,inord,Currindex+1,end);
        
        return node;
        
    }
    
    
    
};