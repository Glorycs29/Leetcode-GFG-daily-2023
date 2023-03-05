class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) { 
         
        vector<long long>sums; 
        queue<TreeNode*>qu; 
        qu.push(root); 
        while(qu.size()>0){ 
            int l=qu.size(); 
            long long sum=0; 
            for(int i=0;i<l;i++){ 
                auto top=qu.front(); 
                qu.pop(); 
                sum+=top->val; 
                if(top->left){ 
                    qu.push(top->left); 
                } 
                if(top->right){ 
                    qu.push(top->right); 
                } 
            } 
            sums.push_back(sum); 
        } 
        sort(sums.begin(),sums.end()); 
        if(sums.size()<k) 
        return -1; 
        return sums[sums.size()-k]; 
    }
};
