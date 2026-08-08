void gameOfLife(int** board, int row, int* cols){
    int next[row][cols[0]], neighbors;

    for(int i=0; i<row; i++){
        for(int j=0; j<cols[0]; j++){
            neighbors = (i>0             &&board[i-1][ j ])  /* North */
                + (i>0     &&j>0         &&board[i-1][j-1])  /* NorthWest */
                + (          j>0         &&board[ i ][j-1])  /* West */
                + (i<row-1 &&j>0         &&board[i+1][j-1])  /* SouthWest */
                + (i<row-1               &&board[i+1][ j ])  /* South */
                + (i<row-1 &&j<cols[0]-1 &&board[i+1][j+1])  /* SouthEast */
                + (          j<cols[0]-1 &&board[ i ][j+1])  /* East */
                + (i>0     &&j<cols[0]-1 &&board[i-1][j+1]); /* NorthEast */
            next[i][j] = neighbors<=1?0 :neighbors==2?board[i][j] :neighbors==3?1:0;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<cols[0]; j++){
            board[i][j] = next[i][j];
        }
    }
}