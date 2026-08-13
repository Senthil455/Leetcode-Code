int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize , n = *obstacleGridColSize;

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    int** res = (int**)malloc(m*sizeof(int*));
    for(int i = 0;i < m;i++)
    {
        res[i] = (int*)calloc(n,sizeof(int));
    }
    res[0][0] = 1;
    
    for(int i = 0; i < m;i++)
    {
        for(int j = 0;j < n;j++)
    {
        if(obstacleGrid[i][j] == 1)
        {
            res[i][j] = 0;
        }
        else
        {
            if(i > 0) res[i][j] += res[i-1][j];
            if(j > 0) res[i][j] += res[i][j-1];
        }
    }
    }
    int result = res[m-1][n-1];
    for(int i = 0; i < m;i++)
        free(res[i]);
    free(res);

    return result;
}