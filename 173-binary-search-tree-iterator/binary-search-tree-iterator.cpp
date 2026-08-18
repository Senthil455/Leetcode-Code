class BSTIterator {
    TreeNode* node = nullptr; 
    stack<TreeNode*> stk; 
public:
    BSTIterator(TreeNode* root): node(root) {}
    
    int next() {
        hasNext(); 
        node = stk.top(); stk.pop(); 
        int ans = node->val; 
        node = node->right; 
        return ans; 
    }
    
    bool hasNext() {
        while (node) {
            stk.push(node); 
            node = node->left; 
        }
        return stk.size(); 
    }
};