/* x ^ n =
{
    (x ^ 2) ^ (n / 2)   if n is even
    x * (x ^ 2) ^ ((n - 1) / 2)   if n is odd
} */

typedef long long _long;

double qmult(double x, _long n)
{
    if(!n)
        return 1.0;
    if(!(n % 2))
        return qmult(x * x, n / 2);
    else
        return x * qmult(x * x, (n - 1) / 2);
}

double myPow(double x, int n)
{
    _long _n = n;
    return n >= 0 ? qmult(x, n) : 1.0 / qmult(x, -_n);
}
