/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
long long sum;
long long count=0;
long long ans=0;
void traverse(struct TreeNode* root,int targetSum){
    if (root==NULL) return;
    sum+=root->val;
    if (sum==targetSum) ans++;
    traverse(root->left,targetSum);
    traverse(root->right,targetSum);
    sum-=root->val;
    return;
}

long long checkeachnode(struct TreeNode* root, int targetSum){
    sum=0;
    if (root==NULL) return 0;
    traverse(root,targetSum);
    checkeachnode(root->left,targetSum);
    checkeachnode(root->right,targetSum);
    return ans;
}

int pathSum(struct TreeNode* root, int targetSum) {
    ans=0;
    return checkeachnode(root,targetSum);
}