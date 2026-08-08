bool isSubsequence(char * s, char * t){
    while (*s && *t) if (*s == *t++) s++;
    return !(*s);
}