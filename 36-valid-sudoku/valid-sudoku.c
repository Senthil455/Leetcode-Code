bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                continue;
            }

            int val = board[r][c] - '1';
            int mask = 1 << val;
            int box_idx = (r / 3) * 3 + (c / 3);

            // Check if this number already exists in row, col, or box
            if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
                return false;
            }

            // Mark the number as seen across all three tracking masks
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[box_idx] |= mask;
        }
    }

    return true;
}