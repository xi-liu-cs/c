#include <stdio.h>

void print(int * a, int r, int c)
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            printf("%d ", a[i * c + j]);
        printf("\n");
    }
}

int main()
{
    int r = 4, c = 4,
    cnt = 0;
    int a[r][c];
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*(a + i) + j) = cnt++;
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
    
    printf("\nprint function:\n");
    print((int *)a, r, c);
    
    for(int i = 0; i < r; ++i)
    {
        printf("a + %d = %p\n", i, a + i);
    }
    
    for(int i = 0; i < r; ++i)
    {
        printf("*(a + %d) = %p, **(a + %d) = %d\n", i, *(a + i), i, **(a + i));
    }
    
    for(int i = 0; i < r; ++i)
    {
        printf("a + %d * c = %p, *(a + %d * c) = %d\n", i, (int *)a + i * c, i, *((int *)a + i * c));
    }
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(*a) = %ld\n", sizeof(*a));
}
