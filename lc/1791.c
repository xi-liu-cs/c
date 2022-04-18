int findCenter(int ** edges, int edges_size, int * edges_col_size)
{
    int n = edges_size + 1; /* from problem: edges.length == n - 1 */
    int * deg = (int *)malloc((n + 1) * sizeof(int));
    memset(deg, 0, (n + 1) * sizeof(int));
    for(int i = 0; i < edges_size; ++i)
    {
        ++deg[edges[i][0]];
        ++deg[edges[i][1]];
    }
    for(int i = 0; i < n + 1; ++i)
    {
        if(deg[i] == n - 1)
        {
            free(deg);
            return i;
        }
    }
    return -1;
}
