#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  void ** a;
  size_t cap, cur;
}vector;

void vector_init(vector * v) 
{
  v->cap = 1;  
  v->a = (void **)malloc(sizeof(*v->a) * v->cap);
  v->cur = 0;
}

void vector_push(vector * v, void * data) 
{
  if(v->cur == v->cap) 
  {
    v->cap *= 2;
    v->a = (void **)realloc(v->a, sizeof(*v->a) * v->cap);
  }
  v->a[v->cur++] = data;
}

int main()
{
    vector v;
    vector_init(&v);
    int data = 0;
    vector_push(&v, &data);
    printf("%d\n", *(int *)*v.a);
}
