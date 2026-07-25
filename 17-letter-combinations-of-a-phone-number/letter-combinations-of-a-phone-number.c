#include <stdlib.h>
#include <string.h>

const char* keypad[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(const char* digits, int index, char* path, int* returnSize, char** result) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(path);
        (*returnSize)++;
        return;
    }
    
    int digit = digits[index] - '0';
    const char* letters = keypad[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        path[index] = letters[i];
        path[index + 1] = '\0';
        backtrack(digits, index + 1, path, returnSize, result);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) return NULL;

    char** result = (char**)malloc(300 * sizeof(char*));
    char* path = (char*)malloc((len + 1) * sizeof(char));
    path[0] = '\0';

    backtrack(digits, 0, path, returnSize, result);
    free(path);
    return result;
}