int threeSumClosest(int * nums, int n, int target)
{
    int cmp(const void * p1, const void * p2){ return *(int *)p1 - *(int *)p2; }
    qsort(nums, n, sizeof(int), cmp);
    int closest = (((unsigned)1 << 31) - 1) >> 1;
    for(int i = 0; i < n; ++i)
    {
        if(i > 0 && nums[i - 1] == nums[i]) /* ignore repeated elements */
            continue;
        int j = i + 1, k = n - 1;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == target)
                return sum;
            if(abs(sum - target) < abs(closest - target))
                closest = sum;
            if(sum < target)
            {
                int _j = j + 1;
                while(_j < k && nums[_j] == nums[j])
                    ++_j;
                j = _j;
            }
            else 
            {
                int _k = k - 1;
                while(j < _k && nums[_k] == nums[k])
                    --_k;
                k = _k;
            }
        }
    } 
    return closest;
}
