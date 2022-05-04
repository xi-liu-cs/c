#include <stdio.h>
#include <stdlib.h>
using namespace std;

template <typename type>
struct vector
{
    type * a;
    int cur_sz;
    int cap_sz;
    vector();
    void push_back(type data);
    type operator[](int i){ return *(a + i); }
    type * data(){ return a; }
};

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
    a.push_back(32);
    printf("a[0] = %d\n", a[0]);
    printf("*a.data() = %d\n", *a.data());
}
