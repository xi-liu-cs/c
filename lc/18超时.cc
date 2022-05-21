bool is_ele_in_set(vector<int> a, int element)
{
    for(int i = 0; i < a.size(); ++i)
        if(a[i] == element)
            return true;
    return false;
}

bool is_set_eq(vector<int> a, vector<int> b)
{
    if(a.size() != b.size())
        return false;
    for(int i = 0; i < a.size(); ++i)
        if(!is_ele_in_set(b, a[i]))
            return false;
    for(int i = 0; i < b.size(); ++i)
        if(!is_ele_in_set(a, b[i]))
            return false;    
    return true;
}

bool is_in_quadruplets(vector<vector<int>> & quadruplets, vector<int> & q)
{
    for(int i = 0; i < quadruplets.size(); ++i)
        if(is_set_eq(quadruplets[i], q))
            return true;
    return false;
}

vector<vector<int>> fourSum(vector<int> & nums, int target) 
{
    vector<vector<int>> quadruplets;
    if(nums.size() < 4)
        return quadruplets;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 3; ++i)
    {
        for(int j = i + 1; j < nums.size() - 2; ++j)
        {
            for(int k = j + 1; k < nums.size() - 1; ++k)
            {
                for(int l = k + 1; l < nums.size(); ++l)
                {
                    vector<int> q = {nums[i], nums[j], nums[k], nums[l]};
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target
                    && !is_in_quadruplets(quadruplets, q))
                        quadruplets.push_back(q);
                }
            }
        }
    }
    return quadruplets;
}
