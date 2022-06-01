#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...)
{
    int sum = 0;
    va_list arg;
    va_start(arg, n);
    for(int i = 0; i < n; ++i)
        sum += va_arg(arg, int);
    va_end(arg);
    return sum;
}

int main()
{
    int n = 3;
    printf("%d\n", sum(n, 1, 2, 3));   
}
