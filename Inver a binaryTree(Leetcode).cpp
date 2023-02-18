class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // invert left and right subtrees recursively
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        // swap left and right subtrees
        root->left = right;
        root->right = left;
        
        return root;
    }  
    
};
