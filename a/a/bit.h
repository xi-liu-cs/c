#include <stdio.h>

void print_bin(int x)
{
    int i = 31;
    while(i >= 0)
    {
        printf("%d", x & (1 << i) ? 1 : 0);
        i--;
    }
    printf("\n");
}