#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct vtex
{
    int vtex_id;
}vtex;

typedef struct edge
{
    vtex * src, * dest;
}edge;

typedef struct graph
{
    int n_vtex, n_edge, cur_edge;
    edge * e_ary;
}graph;

graph * malloc_graph(int n_vtex, int n_edge)
{
    graph * g = (graph *)malloc(sizeof(graph));
    g->n_vtex = n_vtex;
    g->n_edge = n_edge;
    g->cur_edge = 0;
    edge * e_ary = (edge *)malloc(n_edge * sizeof(edge));
    g->e_ary = e_ary;
    return g;
}

void add_edge(graph * g, vtex * src, vtex * dest)
{
    g->e_ary[g->cur_edge].src = src;
    g->e_ary[g->cur_edge].dest = dest;
    ++g->cur_edge;
}

vtex * find(vtex ** parent, vtex * i)
{
    if(!parent[i->vtex_id])
        return i;
    return find(parent, parent[i->vtex_id]);
}

void uni(vtex ** parent, vtex * a, vtex * b)
{
    a = find(parent, a);
    b = find(parent, b);
    parent[a->vtex_id] = b;
}

bool is_cycle(graph * g)
{
    size_t sz = g->n_vtex * sizeof(vtex *);
    vtex ** parent = (vtex **)malloc(sz);
    memset(parent, 0, sz);
    for(int i = 0; i < g->n_edge; ++i)
    {
        vtex * a = find(parent, g->e_ary[i].src);
        vtex * b = find(parent, g->e_ary[i].dest);
        if(a == b)
            return true;
        uni(parent, a, b);
    }
    return false;
}

int main()
{
    int n_vtex = 3, n_edge = 3; /* also modify n_edge if more or less add_edge() calls */
    graph * g = malloc_graph(n_vtex, n_edge);
    vtex data[] = {{0}, {1}, {2}};
    add_edge(g, data, data + 1);
    add_edge(g, data, data + 2);
    add_edge(g, data + 1, data + 2);
    printf("is_cycle = %d\n", is_cycle(g));
}
