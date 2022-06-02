typedef long long _long;

double qmult(double x, _long n)
{
    double ret = 1.0,
    x_c = x; /* x contribute */
    while(n)
    {
        if(n & 1)
            ret *= x_c;
        x_c *= x_c;
        n >>= 1;
    }
    return ret; 
}

double myPow(double x, int n)
{
    _long _n = n;
    return n >= 0 ? qmult(x, n) : 1.0 / qmult(x, -_n);
}
