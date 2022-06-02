/* x ^ n =
{
    (x ^ 2) ^ (n / 2) = (x ^ (n / 2)) ^ 2   if n is even
    x * (x ^ 2) ^ ((n - 1) / 2) = x * (x ^ ((n - 1) / 2)) ^ 2 = x * (x ^ (n / 2)) ^ 2   if n is odd
    y := x ^ (n / 2)
} */

typedef long long _long;

double qmult(double x, _long n)
{
    if(!n)
        return 1.0;
    double y = qmult(x, n / 2);
    return n % 2 ? x * y * y : y * y;
}

double myPow(double x, int n)
{
    _long _n = n;
    return n >= 0 ? qmult(x, n) : 1.0 / qmult(x, -_n);
}
