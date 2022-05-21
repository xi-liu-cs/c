vector<vector<int>> fourSum(vector<int> & nums, int target) 
{
    vector<vector<int>> quadruplets;
    int sz = nums.size();
    if(sz < 4)
        return quadruplets;
    sort(nums.begin(), nums.end());
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
                    quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
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
    return quadruplets;
}
