int binary_search(vector<int> & nums, int target, bool is_left) 
{
    int left = 0, 
    right = nums.size() - 1,
    res = nums.size();
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] > target || (is_left && nums[mid] >= target))
        {
            right = mid - 1;
            res = mid;
        }
        else
            left = mid + 1;
    }
    return res;
}

vector<int> searchRange(vector<int> & nums, int target) 
{
    int left = binary_search(nums, target, true),
    right = binary_search(nums, target, false) - 1;
    if(left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
        return {left, right};
    else
        return {-1, -1};
}
