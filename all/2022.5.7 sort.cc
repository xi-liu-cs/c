#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int w; /* weight */
}edge;

struct graph
{
    vector<int> eg_vec; 
};

int c_cmp(const void * p1, const void * p2){return (*(edge **)p1)->w - (*(edge **)p2)->w;}
int cc_cmp(const void * p1, const void * p2){return ((edge *)p1)->w < ((edge *)p2)->w;}

int main()
{
    edge data[] = {{3}, {2}, {6}, {2}, {1}};
    vector<edge *> v = {data, data + 1, data + 2, data + 3, data + 4};
    for(auto & i: v)
        printf("%d ", i->w);
    printf("\n");
    // qsort(v.data(), v.size(), sizeof(edge *), c_cmp);
    sort(v.begin(), v.end(), cc_cmp);
    for(auto & i: v)
        printf("%d ", i->w);
}
