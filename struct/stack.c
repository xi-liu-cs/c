#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int head, tail, size;
    unsigned block, cur_sz;
    void ** array;
}stack;
 
stack * malloc_stack()
{
    stack * s = (stack *)malloc(sizeof(stack));
    s->head = s->size = 0;
    s->block = s->cur_sz = 32;
    s->tail = s->cur_sz - 1;
    s->array = (void **)malloc(s->cur_sz * sizeof(void *));
    return s;
}

int is_full(stack * s){ return s->size == s->cur_sz; }
int is_empty(stack * s){ return s->size == 0; }

void push(stack * s, void * item)
{
    if (is_full(s))
    {
        s->cur_sz += s->block;
        s->array = (void **)realloc(s->array, s->cur_sz * sizeof(void *));
    }
    s->tail = (s->tail + 1) % s->cur_sz;
    s->array[s->tail] = item;
    ++(s->size);
}

void * pop(stack * s)
{
    if (is_empty(s))
        return 0;
    void * item = s->array[s->tail];
    s->tail = s->tail ? s->tail - 1 : s->head + s->size - 1;
    --(s->size);
    return item;
}

void * rbp(stack * s)
{
    if (is_empty(s))
        return 0;
    return s->array[s->head];
}
 
void * rsp(stack * s)
{
    if (is_empty(s))
        return 0;
    return s->array[s->tail];
}

void print(stack * s)
{
    printf("stack: ");
    for(int i = 0; i < s->size; ++i)
        printf("%d ", *(int *)(s->array[s->tail - i >= 0 ? s->tail - i : s->head + s->size - 1]));
    printf("\n");
}

int main()
{
    stack * s = malloc_stack();
    int data[] = {4, 3, 2, 1, 0};
    push(s, data);
    push(s, data + 1);
    push(s, data + 2);
    push(s, data + 3);
    push(s, data + 4);
    print(s);
    printf("%d popped\n", *(int *)pop(s));
    printf("base item is %d\n", *(int *)rbp(s));
    printf("top item is %d\n", *(int *)rsp(s));
}
