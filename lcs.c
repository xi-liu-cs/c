#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s
{
    int ** c;
    char *** d;
}s;

void p(int ** a, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void p_str(char *** a, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%s ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_lcs(char * a, char *** d, int i, int j)
{
    if(!i || !j)
        return;
    else if(!strcmp(d[i][j], "lp"))
    {
        print_lcs(a, d, i - 1, j - 1);
        printf("%c ", a[i - 1]);
    }
    else if(!strcmp(d[i][j], "up"))
        print_lcs(a, d, i - 1, j);
    else
        print_lcs(a, d, i, j - 1);
}

void helper(char * a, int a_len, char * b, int b_len, char *** d, int i, int j)
{
    if(!i)
    {
        char * buf = malloc(3);
        *buf = b[j];
        strcpy(buf + 1, " ");
        d[i][j] = buf;
    }
    else
    {
        char * buf = malloc(3);
        *buf = a[i];
        strcpy(buf + 1, " ");
        if(i + 1 <= a_len)
            d[i + 1][j] = buf;
    }
    if(!i && !j)
    {
        char * buf = malloc(3);
        *buf = a[i];
        strcpy(buf + 1, " ");
        if(i + 1 <= a_len)
            d[i + 1][j] = buf;
    }
}

s * lcs(char * a, int a_len, char * b, int b_len)
{
    s * ret = malloc(sizeof(s));
    int ** c = malloc((a_len + 1) * sizeof(int *));
    char *** d = malloc((a_len + 1) * sizeof(int **));
    for(int i = 0; i < a_len + 1; i++)
    {
        c[i] = malloc((b_len + 1) * sizeof(int));
        d[i] = malloc((b_len + 1) * sizeof(char *));
    }
    **d = 0;
    for(int i = 0; i <= a_len; i++)
    {
        for(int j = 0; j <= b_len; j++)
        {
            if(!i || !j)
            {
                c[i][j] = 0;
                helper(a, a_len, b, b_len, d, i, j);
            }
            else if(a[i - 1] == b[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = "lp"; /* leftup */
            }
            else if(c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                d[i][j] = "up";
            }
            else
            {
                c[i][j] = c[i][j - 1];
                d[i][j] = "le"; /* left */
            }
        }
    }
    ret->c = c;
    ret->d = d;
    return ret;
}


int main()
{
    char * a = "lyaiyeuwexi";
    char * b = "liuxics";
    int a_len = strlen(a), b_len = strlen(b);
    s * ret = lcs(a, a_len, b, b_len);
    p(ret->c, a_len + 1, b_len + 1);
    p_str(ret->d, a_len + 1, b_len + 1);
    print_lcs(a, ret->d, a_len, b_len);
    return 0;
}
