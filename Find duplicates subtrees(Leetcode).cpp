class Solution {
public:

    string Helper(TreeNode* root, vector<TreeNode*>& ans, map<string,int>& mp){
        if(root==NULL)return "";
        string l="", r="", cur="";
        l+= Helper(root->left, ans, mp);
        r+= Helper(root->right, ans, mp);
        cur= to_string(root->val) + "_" + l + "_" + r;

        if(mp[cur]==1) ans.push_back(root);
        mp[cur]++;
        return cur;    
    }




    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int> mp;
        vector<TreeNode*> ans;
        Helper(root, ans,mp);
        return ans;
    }
};
