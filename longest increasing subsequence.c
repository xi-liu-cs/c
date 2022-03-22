#include <stdio.h>
#include <math.h>

int longest_inc_subseq(int * a, int n)
{
    int memo[n];
    for(int i = 0; i < n; ++i)
    {
        memo[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(a[j] < a[i])
                memo[i] = fmax(memo[i], memo[j] + 1);
        }
    }
    return memo[n - 1];
}

int main()
{
    int a[] = {1, 41, 9, 3, 21, 4, 31};
    int n = sizeof(a) / sizeof(*a);
    printf("longest_inc_subseq = %d\n", longest_inc_subseq(a, n));
}
