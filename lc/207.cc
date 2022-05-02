bool canFinish(int num_course, vector<vector<int>> & prereq) 
{
    vector<vector<int>> adj;
    vector<int> indeg;
    adj.resize(num_course); /* set each element to 0 */
    indeg.resize(num_course);
    for(auto & edge : prereq)
    {
        ++indeg[edge[0]]; 
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    for(int i = 0; i < num_course; ++i)
        if(!indeg[i])
            q.push(i);

    int visited = 0;
    while(!q.empty())
    {
        ++visited;
        int cur = q.front();
        q.pop();
        for(int i = 0; i < adj[cur].size(); ++i)
        {
            --indeg[adj[cur][i]];
            if(!indeg[adj[cur][i]])
                q.push(adj[cur][i]);
        }
    }
    return visited == num_course;
}
