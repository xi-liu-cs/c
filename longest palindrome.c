/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void p(char * a, int start, int len)
{
    for(int i = 0; i < len; ++i)
        printf("%c", a[start + i]);
    printf("\n");
}

int longest_palin_substring(char * a)
{/* consecutive characters */
    int n = strlen(a);
    if(!n)
        return 0;
    bool memo[n][n];
    memset(memo, false, sizeof(memo));
    
    int max_len = 0;
    for(int i = 0; i < n; ++i)
        memo[i][i] = true;    
        
    int start = 0;
    for(int i = 0; i < n - 1; ++i)
    {/* sub_len = 2*/
        if(a[i] == a[i + 1])
        {
            memo[i][i + 1] = true;
            max_len = 2;
            start = i;
        }
    }
    
    for(int sub_len = 3; sub_len <= n; ++sub_len)
    {
        for(int i = 0; i < n - sub_len + 1; ++i)
        {
            int j = i + sub_len - 1;
            if(memo[i + 1][j - 1] && a[i] == a[j])
            {
                memo[i][j] = true;
                if(sub_len > max_len)
                {
                    max_len = sub_len;
                    start = i;
                }
            }
        }
    }
    p(a, start, max_len);
    return max_len;
}

void p(int * a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", a[i * n + j]);
        printf("\n");
    }
}

int longest_palin_subseq(char * a)
{/* consecutive not required */
    int n = strlen(a);
    int memo[n][n];
    memset(memo, 0, sizeof(memo));
    for(int i = 0; i < n; ++i)
        memo[i][i] = 1;
    for(int sub_len = 2; sub_len <= n; ++sub_len)
    {
        for(int i = 0; i < n - sub_len + 1; ++i)
        {
            int j = i + sub_len - 1;
            if(a[i] == a[j])
                memo[i][j] = memo[i + 1][j - 1] + 2;
            else
                memo[i][j] = fmax(memo[i + 1][j], memo[i][j - 1]);
        }
    }
    p((int *)memo, n);
    return memo[0][n - 1];
}

int main()
{
    char * s = "liuywyxi";
    printf("longest_palin_substring = %d\n", longest_palin_substring(s));
    printf("longest_palin_subseq = %d\n", longest_palin_subseq(s));
}
