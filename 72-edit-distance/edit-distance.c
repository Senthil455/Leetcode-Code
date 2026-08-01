#include<string.h>
int min(int a,int b,int c){
    if(a<b && a<c) return a;
    if(b<c) return b;
    return c;
    
}

int minDistance(char* word1, char* word2) {
    int len1=strlen(word1);
    int len2=strlen(word2);
    int dp[len1+1][len2+1];
    for (int i=0;i<=len1;i++){
        for (int j=0;j<=len2;j++){
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
            }
        }
    }
    return dp[len1][len2];
}