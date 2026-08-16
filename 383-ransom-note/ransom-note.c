bool canConstruct(char* ransomNote, char* magazine) {
    int l1=strlen(ransomNote), l2=strlen(magazine);
    if(l1>l2)
        return false;
    int max1=ransomNote[0], max2=magazine[0];
    for(int i=0; i<l1; i++){
        if(max1<ransomNote[i])
            max1=ransomNote[i];
    }
    for(int i=0; i<l2; i++){
        if(max2<magazine[i])
            max2=magazine[i];
    }
    int max=(max1>max2)?max1:max2;
    int * count1= (int *)calloc(max+1, sizeof(int));
    int * count2= (int *)calloc(max+1, sizeof(int));
    for(int i=0; i<l1; i++){
        count1[ransomNote[i]]++;
    }
    for(int i=0; i<l2; i++){
        count2[magazine[i]]++;
    }
    bool out=true;
    for(int i=0;i<=max;i++){
        if(count1[i]>count2[i]){
            out=false;
            break;
        }
    }
    free(count1);
    free(count2);
    return out;
}