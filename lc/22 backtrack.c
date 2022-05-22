char ** ret; int ret_sz, ret_cap;
char * cur; int cur_sz, cur_cap;
int _n, ret_flag = 0, cur_flag = 1;

void _realloc(int flag)
{
    if(flag == ret_flag)
    {
        if(ret_sz + 1 > ret_cap)
        {
            ret_cap *= 2;   
            ret = (char **)realloc(ret, ret_cap * sizeof(char *));
        }
    }
    else if(flag == cur_flag)
    {
        if(cur_sz + 1 > cur_cap)
        {
            cur_cap *= 2;   
            cur = (char *)realloc(cur, cur_cap * sizeof(char));
        }
    }
}

void push_back(char c)
{
    _realloc(cur_flag);
    cur[cur_sz - 1] = c; 
    cur[cur_sz++] = '\0';
}

void pop_back()
{
    --cur_sz;
    if(cur_sz - 1 >= 0)
        cur[cur_sz - 1] = '\0';
}

void backtrack(int open, int close)
{
    if(cur_sz - 1 == 2 * _n)
    {
        _realloc(ret_flag);
        size_t sz = cur_sz * sizeof(char);
        char * buf = (char *)malloc(sz);
        memcpy(buf, cur, sz);
        ret[ret_sz++] = buf;
        return;
    }
    if(open < _n)
    {
        push_back('(');
        backtrack(open + 1, close);
        pop_back();
    }
    if(close < open)
    {
        push_back(')');
        backtrack(open, close + 1);
        pop_back();
    }
}


char ** generateParenthesis(int n, int * return_size)
{
    _n = n;
    ret_sz = cur_sz = 0;
    ret_cap = cur_cap = 1;
    ret = (char **)malloc(ret_cap * sizeof(char *));
    cur = (char *)malloc(cur_cap * sizeof(char));
    *cur = '\0';
    cur_sz = 1;
    backtrack(0, 0);
    *return_size = ret_sz;
    return ret; 
}
