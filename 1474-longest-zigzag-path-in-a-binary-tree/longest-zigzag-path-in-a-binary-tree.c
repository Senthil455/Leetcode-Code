/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define LEFT    -1
#define RIGHT   1
#define START   0

int max = 0;

// Recursion to check all the ZigZag variations
void longestZigZagRecur(struct TreeNode* root, int way, int length_curr)
{
    if(length_curr > max)
    {
        max = length_curr;
    }

    if((root->right == NULL) && (root->left == NULL))
    {
        return;
    }

    if(root->right != NULL)
    {
        longestZigZagRecur(root->right, RIGHT, ((way == LEFT))? length_curr + 1 : 1);
    }

    if(root->left != NULL)
    {
        longestZigZagRecur(root->left, LEFT, ((way == RIGHT))? length_curr + 1 : 1);
    }
}

int longestZigZag(struct TreeNode* root)
{
    max = 0;

    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    longestZigZagRecur(root, START, 1);

    return max;
}