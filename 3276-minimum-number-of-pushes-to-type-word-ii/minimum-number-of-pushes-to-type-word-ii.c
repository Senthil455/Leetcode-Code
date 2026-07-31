int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int minimumPushes(char* word) {
    int cnts[26] = {0};
    int idx = 0;
    while (word[idx] != '\0') {
        cnts[word[idx] - 'a']++;
        ++idx;
    }

    qsort(cnts, 26, sizeof(int), cmp);
    
    int total_press = 0;
    int press_level = 1;
    int letter_idx = 0;
    for (int i = 0; i < 26; ++i) {
        total_press += cnts[i] * press_level;
        letter_idx++;
        press_level = (letter_idx + 8) / 8;
    }

    return total_press;
}