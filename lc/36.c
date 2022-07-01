bool isValidSudoku(char ** board, int board_size, int * board_col_size)
{
    int row[9][9],
    col[9][9],  
    box[3][3][9];
    
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(box, 0, sizeof(box));

    for(int i = 0; i < board_size; ++i)
    {
        for(int j = 0; j < board_col_size[i]; ++j)
        {
            if(board[i][j] != '.')
            {
                int idx = board[i][j] - '0' - 1;
                ++row[i][idx];
                ++col[j][idx];
                ++box[i / 3][j / 3][idx];
                if(row[i][idx] > 1 || col[j][idx] > 1 || box[i / 3][j / 3][idx] > 1)
                    return false;
            }
        }
    }
    return true;
}
