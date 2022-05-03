vector<vector<int>> paths;
vector<int> stk;

void dfs(vector<vector<int>> & graph, int i)
{
    if(i == graph.size() - 1) /* dest = n - 1 */
    {
        paths.push_back(stk);
        return;
    }
    for(auto & j : graph[i])
    {
        stk.push_back(j);
        dfs(graph, j);
        stk.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph) 
{
    stk.push_back(0); /* src = 0 */
    dfs(graph, 0);
    return paths;
}
