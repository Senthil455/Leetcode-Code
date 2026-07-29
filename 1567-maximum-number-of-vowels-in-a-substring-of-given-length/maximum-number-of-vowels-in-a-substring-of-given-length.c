
int maxVowels(char* s, int k) {
    bool isVowel(char chr){
        return chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u';
    }

    int len = strlen(s), max = 0;
    for(int i=0; i<k; i++)
        if(isVowel(s[i])) max++;
    
    int currMax = max;
    
    for(int i=k; i<len; i++){
        if(isVowel(s[i]))
            max++;
        if(isVowel(s[i - k]))
            max--;
        if(max > currMax) currMax = max;
    }
    return currMax;
}