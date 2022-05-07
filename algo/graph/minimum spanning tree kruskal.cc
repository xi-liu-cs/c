#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

struct vtex
{
    int vtex_id;
};

struct dset /* disjoint set union */
{
    vtex ** parent;
    int * rank;
};

struct edge
{
    vtex * src, * dest;
    int weight; 
};

struct graph
{
    int n_vtex;
    vector<edge *> eg_vec; 
};

void add_edge(graph * g, vtex * src, vtex * dest, int weight)
{
    edge * eg = (edge *)malloc(sizeof(edge));
    eg->src = src;
    eg->dest = dest;
    eg->weight = weight;
    g->eg_vec.push_back(eg);
}

dset * malloc_dset(int n_vtex)
{
    dset * d = (dset *)malloc(sizeof(dset));
    int pa_sz = n_vtex * sizeof(vtex *), rk_sz = n_vtex * sizeof(int);
    d->parent = (vtex **)malloc(pa_sz);
    d->rank = (int *)malloc(rk_sz);
    memset(d->parent, 0, pa_sz);
    memset(d->rank, 1, rk_sz);
    return d;
}

graph * malloc_graph(int n_vtex)
{
    graph * g = (graph *)malloc(sizeof(graph));
    g->n_vtex = n_vtex;
    return g;
}

vtex * find(vtex ** parent, vtex * i)
{
    if(!parent[i->vtex_id])
        return i;
    return find(parent, parent[i->vtex_id]);
}

void uni(dset * d, vtex * a, vtex * b)
{
    vtex ** parent = d->parent;
    a = find(parent, a);
    b = find(parent, b);
    int a_id = a->vtex_id, b_id = b->vtex_id;
    int * rank = d->rank; 
    if(a != b)
    {
        if(rank[a_id] < rank[b_id])
        {
            parent[a_id] = b;
            rank[b_id] += rank[a_id];
        }
        else
        {
            parent[b_id] = a;
            rank[a_id] += rank[b_id];
        }
    }
}

void print_weight(vector<edge *> eg_vec)
{
    for(auto & i : eg_vec)
        printf("%d ", i->weight);
    printf("\n");
}

int weight_cmp(const void * p1, const void * p2)
{/* p1 and p2 are addresses of each element */
    return (*(edge **)p1)->weight - (*(edge **)p2)->weight; 
}

vector<edge *> mst_kruskal(graph * g)
{
    vector<edge *> mst;
    dset * d = malloc_dset(g->n_vtex);
    qsort(g->eg_vec.data(), g->eg_vec.size(), sizeof(edge *), weight_cmp);
    print_weight(g->eg_vec);
    for(int i = 0; i < g->eg_vec.size(); ++i)
    {
        if(find(d->parent, g->eg_vec[i]->src) != find(d->parent, g->eg_vec[i]->dest))
        {
            mst.push_back(g->eg_vec[i]);
            uni(d, g->eg_vec[i]->src, g->eg_vec[i]->dest);
            printf("edge %d -> %d has weight %d\n", g->eg_vec[i]->src->vtex_id, g->eg_vec[i]->dest->vtex_id, g->eg_vec[i]->weight);
        }
    }
    return mst;
}

int mst_weight(vector<edge *> mst)
{
    int w = 0;
    for(int i = 0; i < mst.size(); ++i)
        w += mst[i]->weight;
    return w;
}

int main()
{
    graph * g = malloc_graph(4);
    vtex data[] = {{0}, {1}, {2}, {3}};
    add_edge(g, data, data + 1, 10);
    add_edge(g, data + 1, data + 3, 15);
    add_edge(g, data + 2, data + 3, 4);
    add_edge(g, data + 2, data, 6);
    add_edge(g, data, data + 3, 5);
    vector<edge *> mst = mst_kruskal(g);
    printf("mst weight = %d\n", mst_weight(mst));
}
