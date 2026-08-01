int uniquePaths(int m, int n)
{
    int tempMat[m][n];

    for(int i=0;i<m;i++)
    {
        tempMat[i][0]=1;
    }

    for(int i=0;i<n;i++)
    {
        tempMat[0][i]=1;
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            tempMat[i][j]=tempMat[i-1][j]+tempMat[i][j-1];
        }
    }

    return tempMat[m-1][n-1];
}