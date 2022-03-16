int * getRow(int row_index, int * return_size)
{
    *return_size = row_index + 1;
    int ** memo = malloc((*return_size + 1) * sizeof(int *));
    for(int i = 0; i < *return_size; i++)
    {
        memo[i] = malloc((i + 1) * sizeof(int));
        memo[i][0] = memo[i][i] = 1;
        for(int j = 1; j < i; j++)
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
    }
    return memo[row_index];
}
