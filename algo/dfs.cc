#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
using namespace std;

struct vtex
{
    int vtex_id;
};

struct graph 
{
    int n_v;
    bool * visited;
    list<void *> * adj;
    graph(int n_v);
    void add_undirect_edge(void * v1, void * v2);
    void dfs(void * v, void ** tree, int * tree_sz);
    void ** find_span_tree(void * v, int * tree_sz);
};

graph::graph(int n_v)
{
    this->n_v = n_v;
    adj = new list<void *>[n_v];
    visited = (bool *)malloc(n_v * sizeof(bool));
}
 
void graph::add_undirect_edge(void * v1, void * v2)
{
    adj[((vtex *)v1)->vtex_id].push_back(v2);
    adj[((vtex *)v2)->vtex_id].push_back(v1);
}
 
void graph::dfs(void * v, void ** tree, int * tree_sz)
{
    int v_id = ((vtex *)v)->vtex_id;
    visited[v_id] = true;
    tree[(*tree_sz)++] = v; 
    for(list<void *>::iterator i = adj[v_id].begin(); i != adj[v_id].end(); ++i)
        if(!visited[((vtex *)*i)->vtex_id])
            dfs(*i, tree, tree_sz);
}

void ** graph::find_span_tree(void * v, int * tree_sz)
{
    size_t sz = n_v * sizeof(void *);
    void ** tree = (void **)malloc(sz);
    memset(tree, 0, sz);
    *tree_sz = 0;
    dfs(v, tree, tree_sz);
    return tree;
}

void print(void ** a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", ((vtex *)a[i])->vtex_id);
}
 
int main()
{
    vtex data[] = {{0}, {1}, {2}, {3}};
    graph g(4);
    g.add_undirect_edge(data, data + 1);
    g.add_undirect_edge(data, data + 2);
    g.add_undirect_edge(data + 1, data + 2);
    g.add_undirect_edge(data + 2, data);
    g.add_undirect_edge(data + 2, data + 3);
    g.add_undirect_edge(data + 3, data + 3);
    int tree_sz;
    void ** tree = g.find_span_tree(data + 3, &tree_sz);
    print(tree, tree_sz);
}
