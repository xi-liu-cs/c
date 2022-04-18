#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <stack>
using namespace std;

struct graph
{
    int v;
    list<void *> * adj;
    graph(int v);
    void add_edge(void * v1, void * v2);
    void topo_sort_helper(void * v, bool * visited, stack<void *> & s);
    void topo_sort(void * data);
};
 
graph::graph(int v)
{
    this->v = v;
    adj = new list<void *>[v];
}
 
void graph::add_edge(void * v1, void * v2)
{
    adj[*(int *)v1].push_back(v2);
}

void graph::topo_sort_helper(void * v, bool * visited, stack<void *> & s)
{
    int cur_id = *(int *)v;
    visited[cur_id] = true;
    for (list<void *>::iterator i = adj[cur_id].begin(); i != adj[cur_id].end(); ++i)
        if (!visited[*(int *)*i])
            topo_sort_helper(*i, visited, s);
    s.push(v);
}

void graph::topo_sort(void * data)
{
    stack<void *> s;
    bool * visited = (bool *)malloc(v * sizeof(bool));
    memset(visited, false, v * sizeof(bool));
    
    for (int i = 0; i < v; ++i)
        if (!visited[i])
            topo_sort_helper((int *)data + i, visited, s);
            
    while (!s.empty()) 
    {
        printf("%d ", *(int *)s.top());
        s.pop();
    }
}
 
int main()
{
    graph g(6);
    int data[] = {0, 1, 2, 3, 4, 5};
    g.add_edge(data + 5, data + 2);
    g.add_edge(data + 5, data);
    g.add_edge(data + 4, data);
    g.add_edge(data + 4, data + 1);
    g.add_edge(data + 2, data + 3);
    g.add_edge(data + 3, data + 1);
    printf("topo_sort:\n");
    g.topo_sort(data);
}
