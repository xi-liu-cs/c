int ** paths;
int * stk;
int stk_sz;
int stk_cap;
int paths_cap;

void dfs(int i, int ** graph, int graph_sz, int * graph_col_sz, int * ret_sz, int ** return_col_sz)
{
    if(i == graph_sz - 1)
    {
        size_t sz = stk_sz * sizeof(int);
        int * a = (int *)malloc(sz); 
        memcpy(a, stk, sz);
        if(*ret_sz + 1 >= paths_cap)
        {
            paths_cap *= 2;
            paths = (int **)realloc(paths, paths_cap * sizeof(int *));
            *return_col_sz = (int *)realloc(*return_col_sz, paths_cap * sizeof(int));
        }
        paths[*ret_sz] = a;
        (*return_col_sz)[(*ret_sz)++] = stk_sz;
        return; 
    }
    for(int j = 0; j < graph_col_sz[i]; ++j)
    {
        if(stk_sz + 1 > stk_cap)
        {
            stk_cap *= 2;
            stk = (int *)realloc(stk, stk_cap * sizeof(int));
        }
        int vtex = graph[i][j]; 
        stk[stk_sz++] = vtex;
        dfs(vtex, graph, graph_sz, graph_col_sz, ret_sz, return_col_sz);
        --stk_sz; 
    }
}

int ** allPathsSourceTarget(int ** graph, int graph_sz, int * graph_col_sz, int * ret_sz, int ** return_col_sz)
{
    stk_cap = paths_cap = 32;
    stk = (int *)malloc(stk_cap * sizeof(int));
    paths = (int **)malloc(paths_cap * sizeof(int *));
    *return_col_sz = (int *)malloc(paths_cap * sizeof(int *));
    stk_sz = 0;
    stk[stk_sz++] = 0;
    *ret_sz = 0;
    dfs(0, graph, graph_sz, graph_col_sz, ret_sz, return_col_sz);
    return paths;
}
