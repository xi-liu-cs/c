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

void print(char * fmt, ...)
{
    va_list ap; /* arg ptr */
    int d;
    char c, * s;
    va_start(ap, fmt);
    while(*fmt)
    {
        switch(*fmt++)
        {
            case 'c':
                c = (char)va_arg(ap, int);
                printf("char %c\n", c);
                break;
            case 'd':
                d = va_arg(ap, int);
                printf("int %d\n", d);
                break;
            case 's':
                s = va_arg(ap, char *);
                printf("string %s\n", s);
                break;
        }
    }
    va_end(ap);
}

int main()
{
    int n = 3;
    print("%d", sum(n, 1, 2, 3));   
    char c = 'a';
    print("%c", c);
    char * s = "ab";
    print("%s", s);
}
