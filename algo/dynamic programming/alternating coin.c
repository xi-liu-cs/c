#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* in each turn, a player selects either
the first or last coin from the row,
removes it from the row
determine the maximum possible
amount of money we can
definitely win if we move first */

int a[] = {1, 1000, 5, 20, 10};
int n = sizeof(a) / sizeof(*a);

int coin_rec(int i, int j)
{
    if(i > j)
        return 0;
    return fmax(a[i] + fmin(coin_rec(i + 2, j), coin_rec(i + 1, j - 1)) /* opponent select i + 1 or j */,
                a[j] + fmin(coin_rec(i + 1, j - 1), coin_rec(i, j - 2)) /* opponent select i or j - 1 */);
}

int coin(int *** m)
{
    int ** memo = malloc(n * sizeof(int *));
    *m = memo;
    for(int i = 0; i < n; ++i)
    {
        size_t sz = n * sizeof(int);
        memo[i] = malloc(sz);
        memset(memo[i], 0, sz);
    }
    for(int diag = 0; diag < n; ++diag)
    {
        for(int i = 0, j = diag; j < n; ++i, ++j)
        {/* only use values from upper right triangular matrix */
            int a1 = (i + 2) <= j ? memo[i + 2][j] : 0;
            int a2 = ((i + 1) <= (j - 1)) ? memo[i + 1][j - 1] : 0;
            int a3 = (i <= (j - 2)) ? memo[i][j - 2] : 0;
            memo[i][j] = fmax(a[i] + fmin(a1, a2),
                              a[j] + fmin(a2, a3));
        }
    }
    return memo[0][n - 1];
}

void p1(int ** a)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void p2()
{
    for(int diag = 0; diag < n; ++diag)
    {
        for(int i = 0, j = diag; j < n; ++i, ++j)
            printf("(%d, %d)", i, j);
        printf("\n");
    }
}

int main()
{
   printf("coin_rec = %d\n", coin_rec(0, n - 1));
   
   int ** m;
   printf("coin = %d\n", coin(&m));
   printf("\n");
  
   printf("memo:\n");
   p1(m);
   printf("\n");
   
   printf("cells filled\n");
   p2();
}
