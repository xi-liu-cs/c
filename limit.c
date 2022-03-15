#include <stdio.h>
#include <limits.h>

int main()
{
    printf("1 << 31 = %d\n", 1 << 31);
    printf("INT_MIN = %d\n\n", INT_MIN);
    
    printf("1 << 31 = %d\n", (1 << 31) - 1);
    printf("INT_MAX = %d\n", INT_MAX);
}
