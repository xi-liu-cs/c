int singleNumber(int * nums, int nums_size)
{
    int ret = 0;
    for(int i = 0; i < nums_size; i++)
        ret ^= nums[i];
    return ret;
}
