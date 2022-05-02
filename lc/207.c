bool canFinish(int num_course, int ** prereq, int prereq_size, int * prereq_col_size)
{
    int ** adj = (int **)malloc(num_course * sizeof(int *)); /* adjacency list */
    for(int i = 0; i < num_course; ++i)
        adj[i] = (int *)malloc(0); /* prepare realloc */
    int list_size[num_course], indeg[num_course];
    memset(list_size, 0, sizeof(list_size));
    memset(indeg, 0, sizeof(indeg));
    for(int i = 0; i < prereq_size; ++i)
    {
        int a = prereq[i][1], b = prereq[i][0]; /* {b, a} means an edge a -> b */
        ++list_size[a];
        ++indeg[b];
        adj[a] = (int *)realloc(adj[a], list_size[a] * sizeof(int));
        adj[a][list_size[a] - 1] = b; /* add vertex b to end of adjacency list of a */
    }

    int q[num_course];
    int l = 0, r = -1;
    for(int i = 0; i < num_course; ++i)
        if(!indeg[i]) /* course with no prereq can be taken first */
            q[++r] = i;
    
    int visited = 0;
    while(l <= r)
    {
        int cur = q[l++];
        ++visited; /* take course cur */
        for(int i = 0; i < list_size[cur]; ++i)
        {
            --indeg[adj[cur][i]];
            if(!indeg[adj[cur][i]])
                q[++r] = adj[cur][i];
        }
    }
    return visited == num_course;
}
