vector<vector<int>> paths;
vector<int> stk;

void dfs(vector<vector<int>> & graph, int i)
{
    if(i == graph.size() - 1) /* dest = n - 1 */
        paths.push_back(stk);
    for(auto & v : graph[i])
    {
        stk.push_back(v);
        dfs(graph, v);
        stk.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph) 
{
    stk.push_back(0); /* src = 0 */
    dfs(graph, 0);
    return paths;
}
