int maxProfit(int * prices, int prices_size)
{
    int min = ((unsigned int) 1 << 31) - 1;
    int ret = 0;
    for(int i = 0; i < prices_size; i++)
    {
        min = fmin(min, prices[i]);
        ret = fmax(ret, prices[i] - min);
    }
    return ret;
}
