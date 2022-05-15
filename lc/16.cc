int threeSumClosest(vector<int> & nums, int target) 
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int closest = (((unsigned)1 << 31) - 1) >> 1;
    auto update = [&](int sum)
    {
        if(abs(sum - target) < abs(closest - target))
            closest = sum;
    };
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
            update(sum);
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
