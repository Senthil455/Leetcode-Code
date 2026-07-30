/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int dfs(struct TreeNode* node, int maxVal) {
    if (node == NULL) {
        return 0; 
    }
    int count = 0;
    if (node->val >= maxVal) {
        count = 1; 
    }
    int newMax = (node->val > maxVal) ? node->val : maxVal;
    count += dfs(node->left, newMax);
    count += dfs(node->right, newMax);

    return count;
}

int goodNodes(struct TreeNode* root) {
    return dfs(root, root->val);  
}