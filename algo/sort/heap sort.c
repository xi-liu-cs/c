#include <stdio.h>
#define parent(i) ((i - 1) >> 1) /* floor((i - 1) / 2) */
#define left(i) ((i << 1) + 1) /* 2i + 1 */  
#define right(i) ((i << 1) + 2) /* 2i + 2 */ 

typedef struct vtex
{
    int vtex_id;
}vtex;

void swap(vtex ** a , int i, int j)
{
    vtex * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void min_heapify(vtex ** a, int i, int n)
{
    int l = left(i), r = right(i), min_i = i;
    if(l < n && a[l]->vtex_id < a[min_i]->vtex_id)
        min_i = l;
    if(r < n && a[r]->vtex_id < a[min_i]->vtex_id)
        min_i = r;
    if(min_i != i)
    {
        swap(a, i, min_i);
        min_heapify(a, min_i, n);
    }
}
 
void build_min_heap(vtex ** a, int n)
{
    for(int i = n / 2 - 1; i >= 0; --i)
        min_heapify(a, i, n);
}

void heap_sort(vtex ** a, int n)
{
    build_min_heap(a, n);
    for(int i = n - 1; i >= 1; --i)
    {
        swap(a, 0, i);
        min_heapify(a, 0, i);
    }
}
 
void print(vtex ** a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]->vtex_id);
    printf("\n");
}

int main()
{
    vtex data[] = {{4}, {3}, {2}, {9}, {1}};
    vtex * a[] = {data, data + 1, data + 2, data + 3, data + 4};
    int n = sizeof(a) / sizeof(*a);
    print(a, n);
    heap_sort(a, n);
    print(a, n);
}
