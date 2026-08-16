bool wordPattern(char* pattern, char* s) {
    char *arr[27]={0};
    int plen=strlen(pattern);
    char *usedWord[27]={0};
    int usedCt=0;
    char *w;
    w=strtok(s," ");
    arr[pattern[0]-97]=w;
    usedCt++;
    usedWord[0]=w;
    for(int i=1; i<plen; i++){
        w=strtok(NULL," ");
        if(arr[pattern[i]-97]==0){
            if(w==NULL) return false;
            for (int j=0; j<usedCt; j++){
                if(strcmp(usedWord[j],w)==0){
                    return false;
                }
            }
            usedWord[usedCt++]=w;
            arr[pattern[i]-97]=w;
        }
        else{
            if(strcmp(arr[pattern[i]-97],w)!=0){
                return false;
            }
        }
    }
    if((w=strtok(NULL," "))!=NULL){
        printf("%s",w);
        return false;
    }
    return true;
}