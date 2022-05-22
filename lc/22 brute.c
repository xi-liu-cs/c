#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ** ret; int ret_sz = 0, ret_cap = 1;
char * cur; int cur_sz = 0, cur_cap = 1;
int _n;

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

void push_back(char ** cur, char c)
{
    if(cur_sz + 1 > cur_cap)
    {
        cur_cap *= 2;
        *cur = (char *)realloc(*cur, cur_cap * sizeof(char));
    }
    if(*cur)
    {
        (*cur)[cur_sz - 1] = c;
        (*cur)[cur_sz++] = '\0';   
    }
}

void pop_back(char ** cur)
{
    if(cur_sz - 2 >= 0)
        (*cur)[cur_sz - 2] = '\0';
    --cur_sz;
}

void generate()
{
    if(cur_sz - 1 == 2 * _n) /* since cur_sz includes '\0' */
    {
        if(valid())
        {
            if(ret_sz + 1 > ret_cap)
            {
                ret_cap *= 2;
                ret = (char **)realloc(ret, ret_cap * sizeof(char *));
            }
            char * buf = (char *)malloc(cur_sz * sizeof(char));
            memcpy(buf, cur, cur_sz * sizeof(char));
            ret[ret_sz++] = buf; 
        }
        return;
    }
    push_back(&cur, '(');
    generate();
    pop_back(&cur);
    push_back(&cur, ')');
    generate();
    pop_back(&cur);
}

char ** generateParenthesis(int n, int * return_size)
{
    _n = n;
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
    char ** ret = generateParenthesis(3, &retsz);
    for(int i = 0; i < retsz; ++i)
        printf("i = %d, %s\n", i, ret[i]);
}
