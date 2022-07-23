#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vector_struct(type)\
  typedef struct\
  {\
    type * a;\
    size_t cap, cur;\
  }type##_vector; 

#define vector_init(type)\
  void type##_vector_init(type##_vector * v)\
  {\
    v->cap = 1;\
    v->a = malloc(sizeof(type) * v->cap);\
    v->cur = 0;\
  }\

#define vector_push(type)\
  void type##_vector_push(type##_vector * v, type data)\
  {\
    if (v->cur == v->cap)\
    {\
      v->cap *= 2;\
      v->a = realloc(v->a, sizeof(type) * v->cap);\
    }\
    v->a[v->cur++] = data;\
  }

#define vector(type)\
  vector_struct(type);\
  vector_init(type) vector_push(type)

int main() 
{
  vector(int);
  int_vector v;
  int_vector_init(&v);
  int_vector_push(&v, 0);
  printf("%d\n", *v.a);
}
