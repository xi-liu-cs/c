typedef long long _long;

double qmult(double x, _long n)
{
    double ret = 1.0,
    x_contri = x;
    while(n > 0)
    {
        if(n % 2 == 1)
            ret *= x_contri;
        x_contri *= x_contri;
        n /= 2;
    }
    return ret; 
}

double myPow(double x, int n)
{
    _long _n = n;
    return n >= 0 ? qmult(x, n) : 1.0 / qmult(x, -_n);
}
