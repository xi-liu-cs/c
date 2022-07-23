/* put numbers in nums to a hash map, enumerate positive number from 1
check if it is in hash map 
constant space, use nums as hash map */

int firstMissingPositive(int * nums, int n)
{
    for(int i = 0; i < n; ++i)
        if(nums[i] <= 0)
            nums[i] = n + 1;
    for(int i = 0; i < n; ++i)
    {
        int j = abs(nums[i]);
        if(j <= n) /* original input nums[i] > 0 */
            nums[j - 1] = -abs(nums[j - 1]); /* put a number into hash map */
    }
    for(int i = 0; i < n; ++i)
        if(nums[i] > 0)
            return i + 1;
    return n + 1;
}
