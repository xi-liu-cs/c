bool row[9][9],
col[9][9],
box[3][3][9],
valid;
vector<pair<int, int>> space;

void dfs(vector<vector<char>> & board, int space_i)
{
    if(space_i == space.size())
    {
        valid = true;
        return;
    }
    auto [i, j] = space[space_i];
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

void solveSudoku(vector<vector<char>> & board) 
{
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));

    valid = false;
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(board[i][j] == '.')
                space.emplace_back(i, j);
            else
            {
                int idx = board[i][j] - '0' - 1;
                row[i][idx] = col[j][idx] = box[i / 3][j / 3][idx] = true;
            }
        }   
    }
    dfs(board, 0);
}
