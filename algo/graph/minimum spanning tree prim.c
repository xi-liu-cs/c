#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define parent(i) ((i - 1) >> 1) /* floor((i - 1) / 2) */
#define left(i) ((i << 1) + 1) /* 2i + 1 */  
#define right(i) ((i << 1) + 2) /* 2i + 2 */ 
 
typedef struct vtex 
{
    int dest;
    int weight;
    struct vtex * next;
}vtex;

typedef struct adjlist
{
    vtex * head;
}adjlist;

typedef struct graph
{
    int n_vtex;
    adjlist * adj;
}graph;
 
vtex * malloc_vtex(int dest, int weight)
{
    vtex * v = (vtex *)malloc(sizeof(vtex));
    v->dest = dest;
    v->weight = weight;
    v->next = 0;
    return v;
}
 
graph * malloc_graph(int n_vtex)
{
    graph * g = (graph *)malloc(sizeof(graph));
    g->n_vtex = n_vtex;
    g->adj = (adjlist *)malloc(n_vtex * sizeof(adjlist));
    memset(g->adj, 0, n_vtex * sizeof(adjlist));
    return g;
}
 
void add_edge(graph * g, int src, int dest, int weight)
{
    vtex * v = malloc_vtex(dest, weight);
    v->next = g->adj[src].head;
    g->adj[src].head = v; 
 
    v = malloc_vtex(src, weight);
    v->next = g->adj[dest].head;
    g->adj[dest].head = v;
}

typedef struct min_heap_vtex 
{
    int v;
    int key;
}min_heap_vtex;
 
typedef struct min_heap 
{
    min_heap_vtex ** a;
    int cur_sz;
    int cap_sz;
    int * pos; /* decrease_key() */
}min_heap;
 
min_heap_vtex * malloc_min_heap_vtex(int v, int key)
{
    min_heap_vtex * m = (min_heap_vtex *)malloc(sizeof(min_heap_vtex));
    m->v = v;
    m->key = key;
    return m;
}

min_heap * malloc_min_heap(int cap_sz)
{
    min_heap * m = (min_heap *)malloc(sizeof(min_heap));
    m->a = (min_heap_vtex **)malloc(cap_sz * sizeof(min_heap_vtex *));
    m->cur_sz = 0;
    m->cap_sz = cap_sz;
    m->pos = (int *)malloc(cap_sz * sizeof(int));
    return m;
}
 
void swap_min_heap_vtex(min_heap_vtex ** a, min_heap_vtex ** b)
{
    min_heap_vtex * t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(min_heap * a, int i)
{
    int l = left(i), r = right(i), min_i = i;
    if(l < a->cur_sz && a->a[l]->key < a->a[min_i]->key)
        min_i = l;
    if(r < a->cur_sz && a->a[r]->key < a->a[min_i]->key)
        min_i = r;
    if(min_i != i) 
    {
        a->pos[a->a[i]->v] = min_i;
        a->pos[a->a[min_i]->v] = i;
        swap_min_heap_vtex(a->a + min_i, a->a + i);
        min_heapify(a, min_i);
    }
}

int is_empty(min_heap * a)
{
    return a->cur_sz == 0;
}

min_heap_vtex * extract_min(min_heap * a)
{
    if (is_empty(a))
        return 0;
    min_heap_vtex * root = *a->a, * last_vtex = a->a[a->cur_sz - 1];
    *a->a = last_vtex;
    a->pos[root->v] = a->cur_sz - 1;
    a->pos[last_vtex->v] = 0;
    --a->cur_sz;
    min_heapify(a, 0);
    return root;
}

void decrease_key(min_heap * a, int v, int key)
{/* decrease key of vertex v, use pos[] to get current index of node in min heap */
    int i = a->pos[v];
    a->a[i]->key = key;
    while (i && a->a[parent(i)]->key > a->a[i]->key) 
    {/* O(lg n) loop */
        a->pos[a->a[i]->v] = parent(i);
        a->pos[a->a[parent(i)]->v] = i;
        swap_min_heap_vtex(a->a + i, a->a + parent(i));
        i = parent(i);
    }
}

bool is_in_min_heap(min_heap * a, int v)
{
    if(a->pos[v] < a->cur_sz)
        return true;
    return false;
}
 
void print_edge(int * parent, int n)
{
    for (int i = 1; i < n; ++i)
        printf("%d -> %d\n", parent[i], i);
}

void mst_prim(graph * g)
{
    int n_vtex = g->n_vtex;
    int parent[n_vtex]; /* constructed mst */
    int key[n_vtex]; /* Key values used to pick minimum weight edge in cut */
    min_heap * q = malloc_min_heap(n_vtex); /* min priority queue */
    for(int v = 1; v < n_vtex; ++v) 
    {
        parent[v] = -1;
        key[v] = ((unsigned)1 << 31) - 1;
        q->a[v] = malloc_min_heap_vtex(v, key[v]);
        q->pos[v] = v;
    }
    key[0] = 0; /* make 0th vertex extracted first */
    *q->a = malloc_min_heap_vtex(0, key[0]);
    *q->pos = 0;
    q->cur_sz = n_vtex;
    while (!is_empty(q)) 
    {/* q contains all nodes not yet added to mst */
        min_heap_vtex * min_vtex = extract_min(q);
        int u = min_vtex->v;
        for(vtex * i = g->adj[u].head; i; i = i->next) 
        {
            int v = i->dest;
            if (is_in_min_heap(q, v) && i->weight < key[v])
            {
                parent[v] = u;
                key[v] = i->weight;
                decrease_key(q, v, key[v]);
            }
        }
    }
    print_edge(parent, n_vtex);
}

int main()
{
    int n_vtex = 9;
    graph * g = malloc_graph(n_vtex);
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 7, 8);
    add_edge(g, 1, 2, 8);
    add_edge(g, 1, 7, 11);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 8, 2);
    add_edge(g, 2, 5, 4);
    add_edge(g, 3, 4, 9);
    add_edge(g, 3, 5, 14);
    add_edge(g, 4, 5, 10);
    add_edge(g, 5, 6, 2);
    add_edge(g, 6, 7, 1);
    add_edge(g, 6, 8, 6);
    add_edge(g, 7, 8, 7);
    mst_prim(g);
}
