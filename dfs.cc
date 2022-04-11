#include <stdio.h>
#include <list>
#include <map>
using namespace std;

struct graph 
{
    map<int, bool> visited;
    map<int, list<int>> adj;
    void add_edge(int v1, int v2);
    void dfs(int v);
};
 
void graph::add_edge(int v1, int v2)
{
    adj[v1].push_back(v2);
}
 
void graph::dfs(int v)
{
    visited[v] = true;
    printf("%d ", v);
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            dfs(*i);
}
 
int main()
{
    graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.dfs(2);
}
