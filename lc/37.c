bool row[9][9],
col[9][9],
box[3][3][9],
valid;
int * space[81],
space_sz;

void dfs(char ** board, int space_i)
{
    if(space_i == space_sz)
    {
        valid = true;
        return;
    }
    int i = *space[space_i], j = space[space_i][1];
    for(int idx = 0; idx < 9; ++idx)
    {
        if(!row[i][idx] && !col[j][idx] && !box[i / 3][j / 3][idx] && !valid)
        {
            row[i][idx] = col[j][idx] = box[i / 3][j / 3][idx] = true;
            board[i][j] = '0' + idx + 1;
            dfs(board, space_i + 1);
            row[i][idx] = col[j][idx] = box[i / 3][j / 3][idx] = false;
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));
    space_sz = 0;
    valid = false;
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(board[i][j] == '.')
            {
                int * a = (int *)malloc(2 * sizeof(int));
                *a = i; a[1] = j;
                space[space_sz++] = a;
            }
            else
            {
                int idx = board[i][j] - '0' - 1;
                row[i][idx] = col[j][idx] = box[i / 3][j / 3][idx] = true;
            }
        }   
    }
    dfs(board, 0);
}
