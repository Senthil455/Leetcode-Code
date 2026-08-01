/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 :) */
void backtrack(int* candidates, int candidatesSize, int*** ret, int* p, int** returnColumnSizes, int* array, int index, int sum, int k, int n, int start)
{
    if (sum > n)
        return;
    if (sum == n && k == index)
    {
        (*ret)[*p] = malloc(sizeof(int) * index);
        for (int k = 0; k < index; k++)
            (*ret)[*p][k] = array[k];
        (*returnColumnSizes)[*p] = index;
        (*p)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++)
    {
        sum = sum + candidates[i];
        array[index++] = candidates[i];
        backtrack(candidates, candidatesSize, ret, p, returnColumnSizes, array, index, sum, k, n, i + 1);
        sum = sum - candidates[i];
        index--;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
    int candidates[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int candidatesSize = 9;
    int* array = malloc(sizeof(int) * candidatesSize);
    int** ret = malloc(sizeof(int*) * 70);
    *returnColumnSizes = malloc(sizeof(int) * 70);
    int p = 0;
    backtrack(candidates, candidatesSize, &ret, &p, returnColumnSizes, array, 0, 0, k, n, 0);
    ret = realloc(ret, sizeof(int*) * p);
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * p);
    *returnSize = p;
    return ret;
}