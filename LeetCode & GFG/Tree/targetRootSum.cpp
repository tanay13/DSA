bool findEl(Node* root,int k)
{
    if(root==NULL)
        return false;
    
    if(root->data == k)
        return true;
    
    if(findEl(root->left))
        return true;
    
    else if(findEl(root->right))
        return true; 
    
    else
        return false;
}



int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    if(root1==NULL)
        return 0;
    stack<Node*> nodeStack;
    nodeStack.push(root1);
    int count = 0;
    while(nodeStack.empty()==false)
        {
            Node* node = nodeStack.top();
            nodeStack.pop();
            if(findEl(root2,x-(node->data)))
                count++;
            
            if(node->right)
            {
                nodeStack.push(node->right);
        
            }
            
              if(node->left)
            {
                nodeStack.push(node->left);
        
            }
            
        }
        
        return count;
    
    
}
