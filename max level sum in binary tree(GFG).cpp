class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        
        int ans= INT_MIN;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            int levelSum=0;
            
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                levelSum+=node->data;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            ans= max(ans,levelSum);
        }
        return ans;
    }
};
