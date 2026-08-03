char* minWindow(char* s, char* t) {
    int lenS=strlen(s);
    int lenT=strlen(t);

    if(lenS==0 || lenT==0)return "";

    int need[128]={0};
    int window[128]={0};

    for(int i=0;i<lenT;i++){
        need[(int)t[i]]++;
    }

    int have=0, needCount=0;
    for(int i=0;i<128;i++){
        if(need[i]>0)needCount++;
    }

    int left=0;int right=0;
    int minLen=INT_MAX; int start=0;

    while(right<lenS){
        char c=s[right];
        window[(int)c]++;
        if(need[(int)c]>0 && need[(int)c]==window[(int)c]){
            have++;
        }

        while(have==needCount){
            if((right-left+1)<minLen){
                minLen=right-left+1;
                start=left;
            }
            char d=s[left];
            window[(int)d]--;
            if(need[(int)d]>0 && need[(int)d]>window[(int)d]){
                have--;
            }
            left++;
        }
        right++;
    }
    if(minLen==INT_MAX)return "";
    char * res=malloc((minLen+1)*sizeof(char));
    strncpy(res,s+start,minLen);
    res[minLen]='\0';
    return res;
}