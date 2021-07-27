class Solution {
public:

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        
       unordered_map<string,int> umap;
        
       stack<TreeNode*> nodeStack;
       nodeStack.push(root);
       
        vector<TreeNode*> v;
     
        while(nodeStack.empty()==false)
        {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            string in = "";
            
            treeToString(node,in);
            
            umap[in]++;
            
            if(umap.find(in)!=umap.end() && umap[in]==2)
                v.push_back(node);
            
            
            if(node->right)
            {
                nodeStack.push(node->right);
        
            }
            
              if(node->left)
            {
                nodeStack.push(node->left);
        
            }
            
        }
        
        
        return v;
        
        
            
       
        
   }
    
  void treeToString(TreeNode* root, string& str)
  {
    if (root == NULL)
        return;
 
    str.push_back(root->val + '0');
 
    if (!root->left && !root->right)
        return;
 
    str.push_back('(');
    treeToString(root->left, str);
    str.push_back(')');

    if (root->right) {
        str.push_back('(');
        treeToString(root->right, str);
        str.push_back(')');
    }
}
};