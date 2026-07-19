char* smallestSubsequence(char* s) {
    int freq[26] = {0};
    bool vis[26] = {0};

    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    int n = strlen(s);
    char *stack = (char *)malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; s[i]; i++) {
        char ch = s[i];
        freq[ch - 'a']--;

        if (vis[ch - 'a'])
            continue;

        while (top != -1 &&
               ch < stack[top] &&
               freq[stack[top] - 'a'] > 0) {
            vis[stack[top] - 'a'] = false;
            top--;
        }

        stack[++top] = ch;
        vis[ch - 'a'] = true;
    }

    stack[top + 1] = '\0';
    return stack;
}