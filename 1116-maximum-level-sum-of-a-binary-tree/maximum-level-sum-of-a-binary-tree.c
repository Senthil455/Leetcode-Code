#include <limits.h>
#include <stdlib.h>

/* Definition for a binary tree node. */

int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;

    // Queue for BFS
    struct TreeNode* queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 1;
    int answer = 1;
    int maxSum = INT_MIN;

    while (front < rear) {
        int levelSize = rear - front;
        int levelSum = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            levelSum += node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            answer = level;
        }

        level++;
    }

    return answer;
}
