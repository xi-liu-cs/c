#include <stdio.h>
#include <string.h>

void p1(int r, int c, int (*a)[c])
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void p2(int r, int c, int a[][c])
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}


int main()
{
    int r = 3, c = 4, cnt = 0;
    int a[r][c];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            a[i][j] = cnt++;
    printf("p1:\n");
    p1(r, c, a);
    printf("\np2:\n");
    p2(r, c, a);
}
