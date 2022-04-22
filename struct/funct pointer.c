#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void * data;
    void (* print)(struct node *);
}node;

node * malloc_node(void * data)
{
    node * n = (node *)malloc(sizeof(node));
    n->data = data;
    void print(node * n)
    {
        printf("node:\n");
        printf("%d\n", *(int *)n->data);
    }
    n->print = print;
    return n;
}

int main()
{
    int data = 32;
    node * n = malloc_node(&data);
    n->print(n);
}
