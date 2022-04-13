#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

struct graph 
{
    int n_v;
    bool * visited;
    list<int> * adj;
    graph(int n_v);
    void add_edge(int v1, int v2);
    void dfs(int v);
};

graph::graph(int n_v)
{
    this->n_v = n_v;
    adj = new list<int>[n_v];
    visited = (bool *)malloc(n_v * sizeof(int));
}
 
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
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    g.dfs(2);
}
