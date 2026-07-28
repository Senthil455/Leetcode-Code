int compress(char* chars, int charsSize) {
    int result = 0;
    int i = 0;

    while (i < charsSize) {
        int j = i;

        while (j < charsSize && chars[j] == chars[i]) {
            j++;
        }

        int count = j - i;

        chars[result++] = chars[i];

        if (count > 1) {
            char temp[12];
            sprintf(temp, "%d", count);

            for (int k = 0; temp[k] != '\0'; k++) {
                chars[result++] = temp[k];
            }
        }

        i = j;
    }

    return result;
}