int cmp(const void *a, const void *b){
    return *(unsigned char *)a-*(unsigned char *)b;
}
bool isAnagram(char* s, char* t) {
    int n=strlen(s), m=strlen(t);
    qsort(s,n, sizeof(char), cmp);
    qsort(t,m, sizeof(char), cmp);
    return strcmp(s,t)==0;
}