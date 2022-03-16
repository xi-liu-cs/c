#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   
    int val;
    struct node * prev, * next;
}node;

typedef struct 
{
    node * rsp, * min_rsp;
} MinStack;

MinStack * minStackCreate() 
{
    MinStack * m = malloc(sizeof(MinStack));
    m->rsp = 0;
    node * no = malloc(sizeof(node));
    no->val = ((unsigned int)1 << 31) - 1;
    no->prev = no->next = 0;
    m->min_rsp = no;
    return m;
}

void minStackPush(MinStack * obj, int val) 
{
    node * no = malloc(sizeof(node));
    no->val = val;
    no->next = 0;
    no->prev = obj->rsp;

    if(obj->rsp)
        obj->rsp->next = no;
    obj->rsp = no;

    int min_val = no->val < obj->min_rsp->val ? no->val: obj->min_rsp->val;
    node * min_no = malloc(sizeof(node));
    min_no->val = min_val;
    min_no->prev = obj->min_rsp;
    min_no->next = 0;
    obj->min_rsp->next = min_no;
    obj->min_rsp = min_no;
}

void minStackPop(MinStack * obj) 
{
    node * temp_rsp = obj->rsp, * temp_min_rsp = obj->min_rsp;
    obj->rsp = obj->rsp->prev;
    if(obj->rsp)
        obj->rsp->next = 0;
    obj->min_rsp = obj->min_rsp->prev;
    obj->min_rsp->next = 0;
    free(temp_rsp);
    if(temp_rsp != temp_min_rsp)
        free(temp_min_rsp);
}

int minStackTop(MinStack * obj) 
{
    return obj->rsp->val;
}

int minStackGetMin(MinStack * obj) 
{
    return obj->min_rsp->val;
}

void minStackFree(MinStack * obj) 
{
    free(obj->rsp);
    if(obj->rsp != obj->min_rsp)
        free(obj->min_rsp);
    free(obj);
}

int main()
{
    int val = 1;
    MinStack* obj = minStackCreate();
    minStackPush(obj, val);
    minStackPush(obj, ++val);
    
    int p = minStackTop(obj);
    printf("p = %d\n", p);
    
    int p2 = minStackGetMin(obj);
    printf("p2 = %d\n\n", p2);

    minStackPop(obj);

    int p3 = minStackTop(obj);
    printf("p3 = %d\n", p3);
    
    int p4 = minStackGetMin(obj);
    printf("p4 = %d\n", p4);

    minStackFree(obj);
}
