char* removeStars(char* s) {
    int j = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '*')
            j--;
        else
            s[++j] = s[i];
    }
    s[++j] = '\0';
    return s;
}