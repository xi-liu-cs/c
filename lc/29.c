#define int_min ((unsigned)1 << 31)
#define int_max (int_min - 1)

/* dividend / divisor = mid + reminder
ret true iff mid * divisor >= dividend */
bool qadd(int dividend, int divisor, int mid)
{
    int res = 0, /* current product */
    c = divisor; /* contribute */
    while(mid)
    {
        if(mid & 1)
        {
            /* ensure res + c >= dividend */
            if(c < dividend - res)
                return false;
            res += c;
        }
        if(mid != 1)
        {
            /* ensure c + c >= dividend */
            if(c < dividend - c)
                return false;
            c += c;
        }
        mid >>= 1;
    }
    return true;
}

int divide(int dividend, int divisor) 
{
    if(dividend == int_min)
    {
        if(divisor == -1)
            return int_max;
        if(divisor == 1)
            return int_min;
    }
    if(divisor == int_min)
        return dividend == int_min ? 1 : 0;
    if(!dividend)
        return 0;
    bool rev = false;
    if(dividend > 0)
    {
        dividend = -dividend;
        rev = !rev;
    }
    if(divisor > 0)
    {
        divisor = -divisor;
        rev = !rev;
    }
    int ret = 0, left = 1, right = int_max;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        bool check = qadd(dividend, divisor, mid);
        if(check)
        {
            ret = mid;
            if(mid == int_max)
                break;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return rev ? -ret : ret;
}
