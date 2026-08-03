void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i;
    int k;
    int x;
    int y;

    i = 0;
    k = 0;
    while (i < matrixSize)
    {
        while (k < *matrixColSize)
        {
            if (!(matrix[i][k]))
            {
                x = 0;
                y = k;
                while(x < matrixSize)
                {
                    if (matrix[x][y])
                        matrix[x][y] = -2147483605; // this is a random int
                    x++;
                }
                x = i;
                y = 0;
                while(y < *matrixColSize)
                {
                    if (matrix[x][y])
                        matrix[x][y] = -2147483605;
                    y++;
                }
            }
            k++;
        }
        k = 0;
        i++;
    }
    i = 0;
    k = 0;
    while (i < matrixSize)
    {
        while (k < *matrixColSize)
        {
            if (matrix[i][k] == -2147483605)
                matrix[i][k] = 0;
            k++;
        }
        k = 0;
        i++;
    }
}