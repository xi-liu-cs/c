#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
    int * memo;
    int * cut;
}s;

s * bot_up_cut_rod(int * p, int n)
{
    size_t sz = (n + 1) * sizeof(int);
    int * memo = malloc(sz), * cut = malloc(sz);
    *memo = 0;
    for(int i = 1; i <= n; i++)
    {
        memo[i] = 1 << 31;
        for(int j = 1; j <= i; j++)
        {
            if(p[j] + memo[i - j] > memo[i])
            {
                memo[i] = p[j] + memo[i - j];
                cut[i] = j;
            }
        }
    }
    s * ret = malloc(sizeof(s));
    ret->memo = memo;
    ret->cut = cut;
    return ret;
}

s * print_cut(int * p, int n)
{
    s * ret = bot_up_cut_rod(p, n);
    while(n > 0)
    {
        printf("%d ", ret->cut[n]);
        n -= ret->cut[n];
    }
    printf("\n");
    return ret;
}

void p(int * a, int n)
{
    for(int i = 0; i < n; i++)
        printf(a[i] >= 10 ? "%d " : "%d  ", a[i]);
    printf("\n");
}

void f(s * ret)
{
    free(ret->memo);
    free(ret->cut);
    free(ret);
}

int main()
{
    int price[] = {1 << 31, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = sizeof(price) / sizeof(*price);
    
    for(int i = 0; i < n; i++)
    {
        printf("len = %d:  ", i);
        print_cut(price, i);
    }
    printf("\n");
    
    s * ret = bot_up_cut_rod(price, n);

    printf("i:       ");
    int a[n + 1]; 
    for(int i = 0; i <= n; i++)
        a[i] = i;
    p(a, n);
    
    printf("memo[i]: ");
    p(ret->memo, n);
    
    printf("cut[i]:  ");
    p(ret->cut, n);
    
    f(ret);
}
