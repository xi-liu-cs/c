int findCenter(vector<vector<int>>& edges) 
{
    int n = edges.size() + 1; /* from problem: edges.length == n - 1 */
    vector<int> deg(n + 1, 0);
    for(int i = 0; i < edges.size(); ++i)
    {
        ++deg[edges[i][0]];
        ++deg[edges[i][1]];
    }
    for(int i = 0; i < n + 1; ++i)
    {
        if(deg[i] == n - 1)
            return i;
    }
    return -1;
}
