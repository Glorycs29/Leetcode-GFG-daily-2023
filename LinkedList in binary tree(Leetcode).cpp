class Solution {
public:

    bool findSubPath(ListNode* head, TreeNode* root){
        if(!head)return true;
        if(!root)return false;
        
        return head->val==root->val && (findSubPath(head->next,root->left) || findSubPath(head->next,root->right));

    }


    bool isSubPath(ListNode* head, TreeNode* root) {
        //using dfs helper //simple recersion
        if(!root)return false;
        
        return findSubPath(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
        
    }
};
