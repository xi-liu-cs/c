/* https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/ */

#include <stdio.h>
#include <stdlib.h>

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
    printf("a:\n");
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*(a + i) + j) = cnt++;
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
    
    printf("\nprint a:\n");
    print((int *)a, r, c);
    
    for(int i = 0; i < r; ++i)
    {
        printf("a + %d = %p\n", i, a + i);
    }
    
    for(int i = 0; i < r; ++i)
    {
        printf("*(a + %d) = %p, **(a + %d) = %d\n", i, *((int (*)[c])a + i), i, **((int (*)[c])a + i));
    }
    
    for(int i = 0; i < r; ++i)
    {
        printf("a + %d * c = %p, *(a + %d * c) = %d\n", i, (int *)a + i * c, i, *((int *)a + i * c));
    }
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(*a) = %ld\n", sizeof(*a));
    
    printf("\nary:\n");
    int ** ary = malloc(r * sizeof(int *) + r * c * sizeof(int));
    int * ptr = (int *)(ary + r);
    for(int i = 0; i < r; ++i)
        ary[i] = ptr + i * c;
    cnt = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*(ary + i) + j) = cnt++;
            printf("%d ", *(*(ary + i) + j));
        }
        printf("\n");
    }
    printf("\nprint ary:\n");
    print((int *)(ary + r), r, c);
    
    printf("\narray:\n");
    int * array = malloc(r * c * sizeof(int));
    cnt = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*((int (*)[c])array + i) + j) = cnt++;
            printf("%d ", *(*((int (*)[c])array + i) + j));
        }
        printf("\n");
    }
    printf("\nprint array:\n");
    print(array, r, c);
}
