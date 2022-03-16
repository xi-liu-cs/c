int majorityElement(int * nums, int nums_size)
{
    int candidate = -1, count = 0;
    for(int i = 0; i < nums_size; ++i)
    {
        if(nums[i] == candidate)
            count++;
        else if(--count < 0)
        {
            count = 1;
            candidate = nums[i];
        }
    }
    return candidate;
}
