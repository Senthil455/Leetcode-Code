int minPathSum(int ** grid, int gridSize, int * gridColSize)
{
    for (int i = 1; i < *gridColSize; i++)
        grid[0][i] += grid[0][i-1];
    for (int i = 1; i < gridSize; i++)
        grid[i][0] += grid[i-1][0];

    for (int i = 1; i < gridSize; i++)
        for (int j = 1; j < *gridColSize; j++)
            grid[i][j] += (grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]);

    return grid[gridSize-1][*gridColSize-1];
}