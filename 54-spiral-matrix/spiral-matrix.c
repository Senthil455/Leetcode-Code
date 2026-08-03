/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int i;
    int k;
    int l;
    int *total;

    i = 0;
    k = 0;
    l = 0;
    *returnSize = matrixSize * *matrixColSize;
    total = malloc(*returnSize * (sizeof(int)));
    if (!total)
        return (NULL);
    if (*returnSize == 1)
    {
        total[0] = matrix[0][0];
        return (total);
    }
    while (l < *returnSize)
    {
        while(i < *matrixColSize && matrix[k][i] != 111) // going right
        {
            total[l] = matrix[k][i];
            matrix[k][i] = 111;
            i++;
            l++;
        }
        i--;
        k++;
        while(k < matrixSize && matrix[k][i] != 111) // going down
        {
            total[l] = matrix[k][i];
            matrix[k][i] = 111;
            k++;
            l++;
        }
        i--;
        k--;
        while(i >= 0 && matrix[k][i] != 111) // going left
        {
            total[l] = matrix[k][i];
            matrix[k][i] = 111;
            i--;
            l++;
        }
        i++;
        k--;
        while(k >= 0 && matrix[k][i] != 111) // going up
        {
            total[l] = matrix[k][i];
            matrix[k][i] = 111;
            k--;
            l++;
        }
        k++;
        i++;
    }
    return (total);
}