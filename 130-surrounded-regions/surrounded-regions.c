void capture(char **board, int i, int j)                    // recursively change any connected points to X
{
    if (board[i][j] == 'X')
        return;
    board[i][j] = 'X';
    capture(board, i - 1, j);
    capture(board, i, j - 1);    
    capture(board, i + 1, j);
    capture(board, i, j + 1);
}

void changeChar(char **board, int i, int j, int bSize, int bCol, bool *sur)
{
    if ((i == 0 || j == 0 || i == bSize - 1 || j == bCol - 1) && board[i][j] == 'O')  // if we reach the edge,
        *sur = false;                                                                 // we're not surrounded - this will
    board[i][j] = 'V';                                                                // be passed back to the main function

    if (i > 0 && board[i - 1][j] == 'O')                                              // recursively check for adjacent O's
        changeChar(board, i - 1, j, bSize, bCol, sur);                                // and change to (V)isited
    if (j > 0 && board[i][j - 1] == 'O')                                              
        changeChar(board, i, j - 1, bSize, bCol, sur);
    if (i < bSize - 1 && board[i + 1][j] == 'O')
        changeChar(board, i + 1, j, bSize, bCol, sur);
    if (j < bCol - 1 && board[i][j + 1] == 'O')
        changeChar(board, i, j + 1, bSize, bCol, sur);
}

void solve(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < *boardColSize; j++)
            if (board[i][j] == 'O')
            {
                bool sur = true;
                changeChar(board, i, j, boardSize, *boardColSize, &sur);
                if (sur)                                                    // the changeChar function will change sur to false
                    capture(board, i, j);                                   // if it encoutners an edge. If this doesn't 
            }                                                               // happen, change the island to X's
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < *boardColSize; j++)
            if (board[i][j] != 'X')
                board[i][j] = 'O';
}