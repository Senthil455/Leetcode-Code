/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* validSequence(char* word1, char* word2, int* returnSize) {
    int wd1_len = strlen(word1);
    int wd2_len = strlen(word2);
    int cover[wd1_len + 1];
    cover[wd1_len] = 0;
    /* Pre-compute the `cover` array */
    for (int i = wd1_len - 1, j = wd2_len - 1; i >= 0; i--)
    {
        if (j > 0 && word1[i] == word2[j])
        {
            cover[i] = 1 + cover[i + 1];
            j--;
        }
        else
        {
            cover[i] = cover[i + 1];
        }
    }
    
    /* Find the lexicographically smallest result */
    int *ret = malloc(wd2_len * sizeof(int));
    bool modify = true;
    int i = 0, j = 0;
    *returnSize = 0;
    while (i < wd1_len && j < wd2_len)
    {
        if (word1[i] == word2[j])
        {
            ret[(*returnSize)++] = i;
            j++;
        }
        else
        {
            if (modify && (i + 1 < wd1_len) && (cover[i + 1] >= wd2_len - j - 1))
            {
                modify = false;
                ret[(*returnSize)++] = i;
                j++;
            }
        }
        i++;
    }
    if (j != wd2_len)
    {
        *returnSize = 0;
    }

    return ret;
}