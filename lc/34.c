int binary_search(int * nums, int nums_size, int target, bool is_left) 
{
    int left = 0, 
    right = nums_size - 1,
    res = nums_size;
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

int * searchRange(int * nums, int nums_size, int target, int * return_size)
{
    *return_size = 2;
    int left = binary_search(nums, nums_size, target, true),
    right = binary_search(nums, nums_size, target, false) - 1;
    int * a = (int *)malloc(2 * sizeof(int));
    if(left <= right && right < nums_size && nums[left] == target && nums[right] == target)
        *a = left, a[1] = right;
    else
        *a = -1, a[1] = -1;
    return a;
}
