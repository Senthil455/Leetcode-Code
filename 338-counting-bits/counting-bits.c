/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *total;
    int byte;
    int i;

    *returnSize = n + 1;
    total = malloc(*returnSize * sizeof(int));
    if (!total)
        return (NULL);
    byte = 0;
    i = 0;
    while (i <= n)
    {
        total[i] = 0;
        while (byte)
        {
            total[i] += (byte & 1);
            byte >>= 1;
        }
        i++;
        byte = i;
    }
    return (total);
}