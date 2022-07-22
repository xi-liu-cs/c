vector<pair<int, int>> freq;
vector<vector<int>> res;
vector<int> cur;

void dfs(int pos, int rest)
{
    if(!rest)
    {
        res.push_back(cur);
        return;
    }
    if(pos == freq.size() || rest < freq[pos].first)
        return;
    dfs(pos + 1, rest);
    int most = min(rest / freq[pos].first, freq[pos].second);
    for(int i = 1; i <= most; ++i)
    {
        cur.push_back(freq[pos].first);
        dfs(pos + 1, rest - i * freq[pos].first);
    }
    for(int i = 0; i < most; ++i)
        cur.pop_back();
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    for(int c: candidates)
    {
        if(freq.empty() || c != freq.back().first)
            freq.emplace_back(c, 1);
        else if(c == freq.back().first)
            ++freq.back().second;
    }
    dfs(0, target);
    return res;
}
