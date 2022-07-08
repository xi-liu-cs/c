void dfs(vector<int> & candidates, int target, vector<vector<int>> & res, vector<int> & cur, int i)
{
    if(i == candidates.size())
        return;
    if(!target)
    {
        res.push_back(cur);
        return;
    }
    dfs(candidates, target, res, cur, i + 1);
    if(target - candidates[i] >= 0)
    {
        cur.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], res, cur, i);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> & candidates, int target)
{
    vector<vector<int>> res;
    vector<int> cur;
    dfs(candidates, target, res, cur, 0);
    return res;
}
