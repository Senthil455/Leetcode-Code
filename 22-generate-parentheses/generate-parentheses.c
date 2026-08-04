/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current, int pos,
               int open, int close, int n) {
    // If the current string is complete
    if (pos == 2 * n) {
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    // Add '(' if possible
    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1, open + 1, close, n);
    }

    // Add ')' if valid
    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1, open, close + 1, n);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    // Maximum possible combinations for n <= 8 is safe with 1430
    char **result = (char **)malloc(1430 * sizeof(char *));
    *returnSize = 0;

    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    backtrack(result, returnSize, current, 0, 0, 0, n);

    free(current);
    return result;
}