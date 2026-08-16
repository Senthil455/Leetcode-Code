bool isIsomorphic(char* s, char* t) {
    int mp1[256] = {0};
    int mp2[256] = {0};

    for (int i = 0; s[i] && t[i]; i++) {
        unsigned char a = s[i];
        unsigned char b = t[i];

        if (mp1[a] == 0 && mp2[b] == 0) {
            mp1[a] = b;
            mp2[b] = a;
        } else if (mp1[a] != b || mp2[b] != a) {
            return false;
        }
    }

    return strlen(s) == strlen(t);
}