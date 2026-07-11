int firstUniqChar(char* s) {
    int n = strlen(s);
    int * count = (int *)calloc(26 , sizeof(int));
    for(int i=0; i<n; i++){
        count[s[i] - 'a']++;
    }
    int min = 100000000;
    for(int j=0; j<26;j++){
        if(count[j] == 1){
            for(int i=0 ; i<n; i++){
                if(j == s[i]-'a'){
                    if(min > i){
                        min = i;
                    }
                    break;
                }
            }
        }
    }
    if(min != 100000000){
        return min;
    }
    return -1;
}