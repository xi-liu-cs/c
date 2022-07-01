int row[9],
col[9],
box[3][3],
valid;
int * space[81],
space_sz;

void flip(int i, int j, int idx)
{
    row[i] ^= 1 << idx;
    col[j] ^= 1 << idx;
    box[i / 3][j / 3] ^= 1 << idx;
}

void dfs(char ** board, int space_i)
{
    if(space_i == space_sz)
    {
        valid = true;
        return;
    }
    int i = *space[space_i], j = space[space_i][1];
    int mask = ~(row[i] | col[j] | box[i / 3][j / 3]) & 0x1ff; 
    /* ~(...) can only be true if a digit among row[i], col[j], and box[i / 3][j / 3] are all zeros
    0x1ff = ignore zeros before rightmost 9 zeros */
    for(; mask && !valid; mask &= mask - 1) 
    {
        int idx_mask = mask & -mask; /* -mask is represented as ~mask + 1, mask & ~mask = 0, mask & ~mask + 1 = 1 */
        int idx = __builtin_ctz(idx_mask); /* count trailing zeros */
        flip(i, j, idx);
        board[i][j] = '0' + idx + 1;
        dfs(board, space_i + 1);
        flip(i, j, idx);
    }
}

void solveSudoku(char ** board, int board_size, int * board_col_size)
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
                flip(i, j, idx);
            }
        }   
    }
    dfs(board, 0);
}
