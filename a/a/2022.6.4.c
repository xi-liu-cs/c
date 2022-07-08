#include <stdio.h>

#define binary(a) _binary(#a)
typedef unsigned long long _long;

static inline _long _binary(const char * a)
{
    _long i = 0;
    while(*a) 
    {
        i <<= 1;
        i += *a++ - '0';
    }
    return i;
}

int main()
{
    int a = binary(101);
    printf("%d\n", a);
}
