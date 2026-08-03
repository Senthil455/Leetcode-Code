bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i;
    int k;

    i = 0;
    k = 0;
    while (i < matrixSize)
    {
        while (k < *matrixColSize)
        {
            if (matrix[i][k] == target)
                return (true);
            k++;
        }
        k = 0;
        i++;
    }
    return (false);
}