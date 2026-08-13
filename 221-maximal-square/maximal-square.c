void trav(char** matrix, int m, int n,int**dp){
    if(matrix[m][n]=='0'){
        dp[m][n] = 0;
        return;
    }
   if (m == 0 || n == 0) {
        dp[m][n] = matrix[m][n] - '0';  
    }
    else{
        int a;
        int b;
        int c;
        if(dp[m-1][n]!=-1){
            a=dp[m-1][n];
        }
        else{
            trav(matrix,m-1,n,dp);
            a=dp[m-1][n];
        }
        if(dp[m][n-1]!=-1){
            b=dp[m][n-1];
        }
        else{
            trav(matrix,m,n-1,dp);
            b=dp[m][n-1];

        }
        if(dp[m-1][n-1]!=-1){
            c=dp[m-1][n-1];
        }
        else{
            trav(matrix,m-1,n-1,dp);
            c=dp[m-1][n-1];
        }
        int temp = a<b?a:b;
        temp = temp<c?temp:c;
        dp[m][n]=temp+1;
    }
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int m=matrixSize;
    int n=matrixColSize[0];
    int**dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        dp[i] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) {
                trav(matrix, i, j, dp);
            }
        }
    }
    
    int max=INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(max<dp[i][j]){
                max=dp[i][j];
            }
        }
    }
    return max*max;
}