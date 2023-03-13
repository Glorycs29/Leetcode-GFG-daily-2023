class Solution {
public:

    bool Helper(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL) return false;
        return (root1->val==root2->val)&&Helper(root1->left,root2->right)&&Helper(root1->right,root2->left);
    }

    bool isSymmetric(TreeNode* root) {
         //let's do inorder traversal
         //and check for palindrome after storing it into vector
         if(root==NULL)return true;
         bool ans = Helper(root->left,root->right);
         return ans;
    }
};
