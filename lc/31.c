void swap(int * a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void reverse(int * a, int i, int j)
{
    while(i < j)
    {
        swap(a, i, j);
        ++i; --j;
    }
}

void nextPermutation(int * nums, int nums_size)
{
    int i = nums_size - 2;
    while(i >= 0 && nums[i] >= nums[i + 1])
        --i;
    if(i >= 0)
    {
        int j = nums_size - 1;
        while(j >= 0 && nums[i] >= nums[j])
            --j;
        swap(nums, i, j);
    }
    reverse(nums, i + 1, nums_size - 1);
}
