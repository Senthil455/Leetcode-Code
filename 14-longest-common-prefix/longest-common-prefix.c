char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(sizeof(char) * (strlen(strs[0]) + 1));
    int i = -1;

    do{
        i++;
        prefix[i] = strs[0][i];
        for(int j=0; j < strsSize; j++){
            if(!strs[j][i] || prefix[i] != strs[j][i]) 
                prefix[i] = '\0';
        }
    } while(prefix[i]);
    return prefix;
}