char * mergeAlternately(char * word1, char * word2){
    int n= strlen(word1), m=strlen(word2);
    char *out= (char *)calloc(n+m+1, sizeof(char));
    int k=0;
    int min = (n<=m)? n: m;
    for(int i=0; i<min; i++){
        out[k++] = word1[i];
        out[k++] = word2[i];
    }
    if(n>m){
        for(int i=min; i<n; i++){
            out[k++]= word1[i];
        }
    }
    else{
        for(int i=min; i<m; i++){
            out[k++]= word2[i];
        }
    }
    out[k++]='\0';
    return out;
}