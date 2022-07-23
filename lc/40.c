int ** freq, freq_sz,
** res, * res_col_sz, res_sz,
* cur, cur_sz;

int cmp(const void * p1, const void * p2)
{
    return *(int *)p1 - *(int *)p2;
}

void dfs(int pos, int rest)
{
    if(!rest)
    {
        int sz = cur_sz * sizeof(int);
        int * a = malloc(sz);
        memcpy(a, cur, sz);
        res_col_sz[res_sz] = cur_sz;
        res[res_sz++] = a;
        return;
    }
    if(pos == freq_sz || rest < *freq[pos])
        return;
    dfs(pos + 1, rest);
    int most = fmin(rest / *freq[pos], freq[pos][1]);
    for(int i = 1; i <= most; ++i)
    {
        cur[cur_sz++] = *freq[pos];
        dfs(pos + 1, rest - i * *freq[pos]);
    }
    cur_sz -= most;
}

int ** combinationSum2(int * candidates, int candidates_size, int target, int * return_size, int ** return_column_sizes){
    size_t sz = 100 * sizeof(int *);
    freq = malloc(sz);
    res = malloc(sz);
    res_col_sz = malloc(sz);
    cur = malloc(sz);
    freq_sz = res_sz = cur_sz = 0;
    qsort(candidates, candidates_size, sizeof(int), cmp);
    for(int i = 0; i < candidates_size; ++i)
    {
        if(!freq_sz || candidates[i] != *freq[freq_sz - 1])
        {
            freq[freq_sz] = malloc(2 * sizeof(int));
            *freq[freq_sz] = candidates[i];
            freq[freq_sz++][1] = 1;
        }
        else if(candidates[i] == *freq[freq_sz - 1])
            ++freq[freq_sz - 1][1];
    }
    dfs(0, target);
    *return_size = res_sz;
    *return_column_sizes = res_col_sz;
    return res;
}
