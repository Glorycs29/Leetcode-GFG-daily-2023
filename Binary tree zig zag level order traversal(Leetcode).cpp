class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
    	queue<TreeNode*> q;
    	
    	if(root == NULL) return res;
    	
    	q.push(root);
    	int level = 0;
    	while(!q.empty()){
            vector<int> ans;
    	    int size = q.size();
    	    stack<TreeNode*> st;
    	    
    	    for(int i=0;i<size;i++){
    	        TreeNode* cur = q.front();
    	        q.pop();
    	        
    	        ans.push_back(cur->val);
    	        
    	        if(level%2 ==0){
    	            if(cur->left){
    	                st.push(cur->left);
    	            }
    	            if(cur->right){
    	                st.push(cur->right);
    	            }
    	        }else{
    	            if(cur->right){
    	                st.push(cur->right);
    	            }
    	            if(cur->left){
    	                st.push(cur->left);
    	            }
    	        }
    	    }
            res.push_back(ans);
    	    while(!st.empty()){
    	        q.push(st.top());
    	        st.pop();
    	    }
    	    level++;
    	}
        return res;
    
    }
};
