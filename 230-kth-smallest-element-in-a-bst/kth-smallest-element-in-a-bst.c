/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int inorder(struct TreeNode *root, int *k) {
    if (root == NULL) {
        return -1;
    } 

    int left = inorder(root->left, k);
    if (left != -1) {
        return left;
    }

    (*k)--;
    if (*k == 0) {
        return root->val;
    }

    return inorder(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    return inorder(root, &k);
}