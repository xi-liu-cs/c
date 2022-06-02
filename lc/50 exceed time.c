#include <stdio.h>
#include <stdbool.h>

double myPow(double x, int n)
{
    bool rev = false;
    if(n < 0)
    {
        n = -n;
        rev = !rev;
    }
    double ret = 1;
    for(int i = 0; i < n; ++i)
        ret *= x;
    if(rev)
        ret = 1 / ret;
    return ret;
}

int main()
{
    printf("%f\n", myPow(2.1, 3));
    printf("%f\n", myPow(2, -2));
}
