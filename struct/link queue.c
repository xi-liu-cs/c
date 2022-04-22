#include <stdio.h>
#include <stdlib.h>

typedef struct qnode
{
    void * data;
    struct qnode * next;
}qnode;
 
typedef struct queue 
{ struct qnode * head, * tail; } queue;

qnode * malloc_qnode(void * data)
{
    qnode * q = (qnode *)malloc(sizeof(qnode));
    q->data = data;
    q->next = 0;
    return q;
}

queue * malloc_queue()
{
    queue * q = (queue *)malloc(sizeof(queue));
    q->head = q->tail = 0;
    return q;
}
 
void enq(queue * que, void * data)
{
    qnode * qn = malloc_qnode(data);
    if(!que->tail) 
    {
        que->head = que->tail = qn;
        return;
    }
    que->tail->next = qn;
    que->tail = qn;
}

void deq(queue * que)
{
    if (!que->head)
        return;
    qnode * qn = que->head;
    que->head = que->head->next;
    if (!que->head)
        que->tail = 0;
    free(qn);
}

void print(queue * que)
{
    printf("queue: ");
    for(qnode * qn = que->head; qn; qn = qn->next)
        printf("%d ", *(int *)qn->data);
    printf("\n");
}

int main()
{
    queue * q = malloc_queue();
    int data[] = {0, 1, 2, 3, 4};
    enq(q, data);
    enq(q, data + 1);
    deq(q);
    deq(q);
    enq(q, data + 2);
    enq(q, data + 3);
    enq(q, data + 4);
    deq(q);
    print(q);
    return 0;
}
