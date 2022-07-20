int cmp(void * p1, void * p2)
{
    return *(int *)p1 - *(int *)p2;
}

int maximumProduct(int * nums, int n)
{
    qsort(nums, n, sizeof(int), cmp);
    return fmax(nums[0] * nums[1] * nums[n - 1],
    nums[n - 3] * nums[n - 2] * nums[n - 1]);    
}
