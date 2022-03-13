#include <stdio.h>
#include <string.h>

/* a = unsorted array
b = array to hold sorted output */
void count_sort(int * a, int * b, int len)
{
    int max = *a;
    for(int i = 1; i < len; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    int c[max + 1];
    memset(c, 0, (max + 1) * sizeof(int));
    for(int i = 0; i < len; i++)
        c[a[i]]++;
    for(int i = 1; i < max + 1; i++)
        c[i] += c[i - 1];
    for(int i = 0; i < len; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}

void p(int * a, int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {2, 5, 2, 1, 5, 2, 3, 5, 1, 4};
    int len = sizeof(a) / sizeof(*a);
    int b[len];
    count_sort(a, b, len);
    p(b, len);
}
