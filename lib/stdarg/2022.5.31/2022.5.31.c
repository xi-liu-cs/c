#include <stdio.h>
#include <stdarg.h>
 
void _print(size_t n, int * a)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
 
#define print(arg1, ...)                    \
{                                           \
   int _x[] = {arg1, __VA_ARGS__};          \
   _print(sizeof(_x) / sizeof(*_x), _x);    \
}
 
int main()
{
    print(1);
    print(1, 2);
}
