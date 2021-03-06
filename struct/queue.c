#include <stdio.h>
#include <stdlib.h>

typedef struct queue 
{
    int head, tail, size;
    unsigned cur_sz;
    void ** array;
}queue;
 
queue * malloc_queue()
{
    queue * q = (queue *)malloc(sizeof(queue));
    q->head = q->size = 0;
    q->cur_sz = 32;
    q->tail = q->cur_sz - 1;
    q->array = (void **)malloc(q->cur_sz * sizeof(void *));
    return q;
}

int is_full(queue * q){ return q->size == q->cur_sz; }
int is_empty(queue * q){ return q->size == 0; }

void enq(queue * q, void * item)
{
    if (is_full(q))
    {
        q->cur_sz *= 2;
        q->array = (void **)realloc(q->array, q->cur_sz * sizeof(void *));
    }
    q->tail = (q->tail + 1) % q->cur_sz;
    q->array[q->tail] = item;
    ++(q->size);
}

void * deq(queue * q)
{
    if (is_empty(q))
        return 0;
    void * item = q->array[q->head];
    q->head = (q->head + 1) % q->cur_sz;
    --(q->size);
    return item;
}

void * front(queue * q)
{
    if (is_empty(q))
        return 0;
    return q->array[q->head];
}
 
void * back(queue * q)
{
    if (is_empty(q))
        return 0;
    return q->array[q->tail];
}

void print(queue * q)
{
    printf("queue: ");
    for(int i = 0; i < q->size; ++i)
        printf("%d ", *(int *)(q->array[(q->head + i) % q->size]));
    printf("\n");
}

int main()
{
    queue * q = malloc_queue();
    int data[] = {4, 3, 2, 1, 0};
    enq(q, data);
    enq(q, data + 1);
    enq(q, data + 2);
    enq(q, data + 3);
    enq(q, data + 4);
    print(q);
    printf("%d dequeued\n", *(int *)deq(q));
    printf("front item is %d\n", *(int *)front(q));
    printf("back item is %d\n", *(int *)back(q));
}
