/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);

    int count[26] = {0};
    int first[26];
    int last[26];
    int order[26];
    int orderSize = 0;

    for (int i = 0; i < 26; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';

        if (count[c] == 0) {
            first[c] = i;
            order[orderSize++] = c;
        }

        count[c]++;
        last[c] = i;
    }

    int queue[26][3];
    int queueSize = 0;

    char** res = malloc(26 * sizeof(char*));
    *returnSize = 0;

    for (int o = 0; o < orderSize; o++) {
        int c = order[o];

        for (int i = queueSize; i > 0; i--) {
            queue[i][0] = queue[i - 1][0];
            queue[i][1] = queue[i - 1][1];
            queue[i][2] = queue[i - 1][2];
        }

        queue[0][0] = first[c];
        queue[0][1] = last[c];
        queue[0][2] = count[c];
        queueSize++;

        int left = INT_MAX;
        int right = INT_MIN;
        int total = 0;

        for (int i = 0; i < queueSize; i++) {
            total += queue[i][2];

            if (queue[i][0] < left) {
                left = queue[i][0];
            }

            if (queue[i][1] > right) {
                right = queue[i][1];
            }

            if (total == right - left + 1) {
                break;
            }
        }

        if (total == right - left + 1) {
            int len = right - left + 1;

            res[*returnSize] = malloc((len + 1) * sizeof(char));
            memcpy(res[*returnSize], s + left, len);
            res[*returnSize][len] = '\0';

            (*returnSize)++;
            queueSize = 0;
        }
    }

    return res;
}