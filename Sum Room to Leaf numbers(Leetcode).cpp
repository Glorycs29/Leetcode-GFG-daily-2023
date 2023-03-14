class Solution {
public:
    int dfsHelper(TreeNode* root, int cur){
        if(!root) return 0;
        cur = cur*10 + root->val;
        if(!root->left && !root->right){
            return cur; 
        }
        return dfsHelper(root->left, cur) + dfsHelper(root->right, cur);
    }

    int sumNumbers(TreeNode* root) {
        return dfsHelper(root, 0);
    }
};


// iterative dfs preorder

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;      // {node, cur}
        s.push({root, 0});
        int sum = 0;
        while(!s.empty()) {
            auto [root, cur] = s.top(); s.pop();
            cur = cur * 10 + root -> val;
            if(!root -> left && !root -> right) sum += cur;  // reached leaf node
            if(root -> right) s.push({root -> right, cur});
            if(root -> left) s.push({root -> left, cur});
        }
        return sum;
    }
};


// BFS

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            auto [n, cur] = q.front(); q.pop();
            cur = cur * 10 + n -> val;
            if(n -> left) q.push({n -> left, cur});      
            if(n -> right) q.push({n -> right, cur});
            if(!n -> left && !n -> right) sum += cur;   // add to total sum if we are at leaf node
        }
        return sum;
    }
};


