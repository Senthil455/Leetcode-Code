/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode node;
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double* arr = (double*)malloc(sizeof(double)*10001);
    int x = 0;
    node* queue[10001];
    int rear = 0, front = 0;
    queue[rear++] = root;
    while(front < rear){
        int curr = rear - front;
        double ans = 0;
        for(int j = 0; j < curr; ++j){
            node* temp = queue[front++];
            ans += temp->val;
            if(temp->left)
                queue[rear++] = temp->left;
            if(temp->right)
                queue[rear++] = temp->right;
        }
        arr[x++] = ans / curr;
    }
    *returnSize = x;
    return arr;
}