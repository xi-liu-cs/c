#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void p_substr(char * a, int start, int len)
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
    p_substr(a, start, max_len);
    return max_len;
}

void p_subseq(int * a, int n)
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
    p_subseq((int *)memo, n);
    return memo[0][n - 1];
}

int longest_common_subseq(char * a, char * b)
{
    int a_len = strlen(a), b_len = strlen(b);
    int c[a_len + 1][b_len + 1];
    for(int i = 0; i <= a_len; i++)
    {
        for(int j = 0; j <= b_len; j++)
        {
            if(!i || !j)
                c[i][j] = 0;
            else if(a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = fmax(c[i - 1][j], c[i][j - 1]);
        }
    }
    return c[a_len][b_len];
}

char * revstr(char * a)
{
    int a_len = strlen(a);
    char * rev = malloc((a_len + 1) * sizeof(char));
    strcpy(rev, a);
    for(int i = 0, j = a_len - 1; i < j; ++i, --j)
    {
        char t = rev[i];
        rev[i] = rev[j];
        rev[j] = t;
    }
    return rev;
}

int longest_palin_subseq2(char * a)
{
    char * rev = revstr(a);
    return longest_common_subseq(a, rev);
}

int main()
{
    char * s = "liuywyxi";
    printf("longest_palin_substring = %d\n", longest_palin_substring(s));
    printf("longest_palin_subseq = %d\n", longest_palin_subseq(s));
    
    char * a = "liuywyxi";
    char * b = "liuxics";
    printf("%d\n", longest_palin_subseq2(a));
    printf("%d\n", longest_common_subseq(a, b));
}
