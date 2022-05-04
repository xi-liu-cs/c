#include <stdio.h>
#include <stdlib.h>

template <typename type>
struct vector
{
    type * a;
    int cap_sz;
    int cur_sz;
    vector();
    type & operator*(){ return *a; }
    type * operator+(int i){ return a + i; }
    type & operator[](int i){ return *(a + i); }
    type * data(){ return a; }
    void print();
    void push_back(type data);
    void pop_back(){ --cur_sz; }
};

template <typename type>
void vector<type>::print()
{
    for(int i = 0; i < cur_sz; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

template <typename type>
vector<type>::vector()
{
    cap_sz = 1;
    a = (type *)malloc(cap_sz * sizeof(type));
    cur_sz = 0;
}

template <typename type>
void vector<type>::push_back(type data)
{
    if (cur_sz >= cap_sz) 
    {
        cap_sz *= 2;
        a = (type *)realloc(a, cap_sz * sizeof(type));
    }
    a[cur_sz] = data;
    ++cur_sz;
}
 
int main()
{
    vector<int> a;
    for(int i = 0; i < 4; ++i)
        a.push_back(i);
    printf("a[0] = %d\n", a[0]);
    printf("*a.data() = %d\n", *a.data());
    a.print();
    
    a.pop_back();
    *a = 3;
    *(a + 1) = 2;
    a[2] = 1;
    a.print();
}
