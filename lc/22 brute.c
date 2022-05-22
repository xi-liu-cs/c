#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ** ret; int ret_sz, ret_cap;
char * cur; int cur_sz, cur_cap;
int _n, ret_flag = 0, cur_flag = 1;

bool valid()
{
    int balance = 0;
    for(int i = 0; i < cur_sz - 1; ++i)
    {
        if(cur[i] == '(')
            ++balance;
        else if(cur[i] == ')')
            --balance;
        if(balance < 0)
            return false;
    }
    return balance == 0;
}

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

void generate()
{
    if(cur_sz - 1 == 2 * _n)
    {
        if(valid())
        {
            _realloc(ret_flag);
            size_t sz = cur_sz * sizeof(char);
            char * buf = (char *)malloc(sz);
            memcpy(buf, cur, sz);
            ret[ret_sz++] = buf;
        }
        return;
    }
    push_back('(');
    generate();
    pop_back();
    push_back(')');
    generate();
    pop_back();
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
    generate();
    *return_size = ret_sz;
    return ret; 
}

int main()
{
    int retsz;
    char ** ret = generateParenthesis(8, &retsz);
    for(int i = 0; i < retsz; ++i)
        printf("i = %d, %s\n", i, ret[i]);
}
