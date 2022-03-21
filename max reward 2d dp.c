#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

/* a[1 . . . m][1 . . . n], 
where each entry a[i][j] is reward
start from a[0][0], in each step, we are allowed
to move right or down, 
until we reach a[m][n]
collect the reward of each cell we step on */

vector<vector<int>> v
{
    {0,6,0},
    {5,8,7},
    {0,9,0}
};
#define m v.size()
#define n v[0].size()
int * a[3];

void copy()
{
    for(int i = 0; i < m; ++i)
        a[i] = v[i].data();    
}

void p(int * a)
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", a[i * n + j]);
        printf("\n");
    }
}

int max_reward_rec(int i, int j)
{
    if(!i && !j)
        return a[i][j];
    int a1 = (i - 1) >= 0 ? max_reward_rec(i - 1, j) : 0;
    int a2 = (j - 1) >= 0 ? max_reward_rec(i, j - 1) : 0;
    return a[i][j] + fmax(a1, a2);
}

int max_reward()
{
    int memo[m][n];
    memset(memo, 0, sizeof(memo));
    **memo = **a;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!i && !j)
                continue;
            int a1 = (i - 1) >= 0 ? memo[i - 1][j] : 0;
            int a2 = (j - 1) >= 0 ? memo[i][j - 1] : 0;
            memo[i][j] = a[i][j] + fmax(a1, a2);
        }
    }
    p((int *)memo);
    return memo[m - 1][n - 1];
}

int main()
{
    copy();
    printf("max_reward_rec = %d\n", max_reward_rec(m - 1, n - 1));
    printf("max_reward = %d\n", max_reward());
}
