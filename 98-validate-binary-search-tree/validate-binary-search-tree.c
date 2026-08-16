long prev = LONG_MIN;
bool isValid = true;

void inorder(struct TreeNode* root) {
    if (!isValid || !root) return;

    if (root->left) inorder(root->left);

    if (prev >= root->val) {
        isValid = false;
        return;
    }
    prev = root->val;

    if (root->right) inorder(root->right);
}

bool isValidBST(struct TreeNode* root) {
    prev = LONG_MIN; // Reset prev for each call
    isValid = true;  // Reset isValid for each call
    inorder(root);
    return isValid;
}