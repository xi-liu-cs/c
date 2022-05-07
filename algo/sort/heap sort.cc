#include <stdio.h>
#define parent(i) ((i - 1) >> 1) /* floor((i - 1) / 2) */
#define left(i) ((i << 1) + 1) /* 2i + 1 */  
#define right(i) ((i << 1) + 2) /* 2i + 2 */ 

void swap(int * a , int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void min_heapify(int * a, int i, int n)
{
    int l = left(i), r = right(i), min_i = i;
    if(l < n && a[l] < a[min_i])
        min_i = l;
    if(r < n && a[r] < a[min_i])
        min_i = r;
    if(min_i != i)
    {
        swap(a, i, min_i);
        min_heapify(a, min_i, n);
    }
}
 
void build_min_heap(int * a, int n)
{
    for(int i = n / 2 - 1; i >= 0; --i)
        min_heapify(a, i, n);
}

void heap_sort(int * a, int n)
{
    build_min_heap(a, n);
    for(int i = n - 1; i >= 1; --i)
    {
        swap(a, 0, i);
        min_heapify(a, 0, i);
    }
}
 
void print(int * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {4, 3, 2, 9, 1};
    int n = sizeof(a) / sizeof(*a);
    print(a, n);
    heap_sort(a, n);
    print(a, n);
}
