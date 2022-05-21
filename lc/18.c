int cmp(const void * p1, const void * p2)
{
    return *(int *)p1 - *(int *)p2;
}

int cap_sz = 1;
int ** quadruplets;
int * ret_col_sizes;

int ** fourSum(int * nums, int nums_size, int target, int * return_size, int ** return_column_sizes)
{
    quadruplets = (int **)malloc(cap_sz * sizeof(int *)); 
    ret_col_sizes = (int *)malloc(cap_sz * sizeof(int));
    *return_size = 0;
    int sz = nums_size;
    if(sz < 4)
        return quadruplets;
    qsort(nums, sz, sizeof(int), cmp);
    for(int i = 0; i < sz - 3; ++i)
    {
        if(i > 0 && nums[i] == nums[i - 1])
            continue; /* to avoid repeated values, increment i */
        if((long)nums[i] + nums[sz - 3] + nums[sz - 2] + nums[sz - 1] < target) /* i is too small */
            continue; /* increment i */
        if((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) /* i is too big */
            break; /* do not decrement i, since smaller i are already handled */
        for(int j = i + 1; j < sz - 2; ++j)
        {
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue; /* to avoid repeated values, increment j */
            if((long)nums[i] + nums[j] + nums[sz - 2] + nums[sz - 1] < target) /* j is too small */
                continue; /* increment j */
            if((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) /* j is too big */
                break; /* do not decrement j, since smaller j are already handled */
            int left = j + 1, right = sz - 1;
            while(left < right)
            {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target)
                {
                    int tmp[] = {nums[i], nums[j], nums[left], nums[right]};
                    int * buf = (int *)malloc(sizeof(tmp));
                    memcpy(buf, tmp, sizeof(tmp));
                    if(*return_size + 1 > cap_sz)
                    {
                        cap_sz *= 2;
                        quadruplets = (int **)realloc(quadruplets, cap_sz * sizeof(int *));
                        ret_col_sizes = (int *)realloc(ret_col_sizes, cap_sz * sizeof(int));
                    }
                    ret_col_sizes[*return_size] = 4;
                    quadruplets[(*return_size)++] = buf;
                    while(left < right && nums[left] == nums[left + 1])
                        ++left;
                    ++left;
                    while(left < right && nums[right] == nums[right - 1])
                        --right;
                    --right;
                }
                else if(sum < target)
                    ++left;
                else if(sum > target)
                    --right;
            }
        }
    }
    *return_column_sizes = ret_col_sizes;
    return quadruplets;
}
