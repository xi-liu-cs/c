#include <stdio.h>
#include <string.h>
#include <math.h>

int lcs_rec(char * a, int i, char * b, int j, int cnt)
{
    if(!i || !j)
        return cnt;
    if(a[i - 1] == b[j - 1])
        cnt = lcs_rec(a, i - 1, b, j - 1, cnt + 1);
    cnt = fmax(cnt, 
              fmax(lcs_rec(a, i - 1, b, j, 0),
              lcs_rec(a, i, b, j - 1, 0))
              );
    return cnt;
}

int lcs(char * a, int m, char * b, int n)
{
    int memo[m + 1][n + 1];
    int ret = 0;
    for(int i = 0; i <= m; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            if(!i || !j)
                memo[i][j] = 0;
            else if(a[i - 1] == b[j - 1])
            {
                memo[i][j] = memo[i - 1][j - 1] + 1;
                ret = fmax(ret, memo[i][j]);
            }
            else
                memo[i][j] = 0;
        }
    }
    return ret;
}

int main()
{
   char * a = "liuyuxi";
   char * b = "yangyuxi";
   printf("lcs_rec = %d\n", lcs_rec(a, strlen(a), b, strlen(b), 0));
   printf("lcs = %d\n", lcs(a, strlen(a), b, strlen(b)));
}
