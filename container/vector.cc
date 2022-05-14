#include <stdio.h>
#include <stdlib.h>
#include <initializer_list>

template <typename type>
struct iterator
{
    type * a;
    iterator(type * ptr){ a = ptr; }
    iterator & operator++()
    {
        ++a; 
        return *this;
    }
    iterator operator++(int)
    {
        iterator i = *this;
        ++*this;
        return i;
    }
    iterator & operator--()
    {
        --a; 
        return *this;
    }
    iterator operator--(int)
    {
        iterator i = *this;
        --*this;
        return i;
    }
    type & operator[](int i){ return *(a + i); }
    type * operator->(){ return a; }
    type & operator*(){ return *a; }
    bool operator==(const iterator & other) const { return a == other.a; }
    bool operator!=(const iterator & other) const { return !(*this == other); }
};

template <typename type>
struct vector
{
    type * a;
    int cap_sz;
    int cur_sz;
    vector();
    vector(std::initializer_list<type> l);
    type & operator*(){ return *a; }
    type * operator+(int i){ return a + i; }
    type & operator[](int i){ return *(a + i); }
    void operator=(std::initializer_list<type> l);
    type * data(){ return a; }
    void print();
    void push_back(type data);
    void pop_back(){ --cur_sz; }
    using iterator = struct iterator<type>;
    iterator begin(){ return iterator(a); }
    iterator end(){ return iterator(a + cur_sz); }
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
vector<type>::vector(std::initializer_list<type> l)
{
    cap_sz = 1;
    a = (type *)malloc(cap_sz * sizeof(type));
    cur_sz = 0;
    *this = l;
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

template <typename type>
void vector<type>::operator=(std::initializer_list<type> l)
{
    cur_sz = cap_sz = l.size();
    a = (type *)malloc(l.size() * sizeof(type));
    typename std::initializer_list<type>::iterator it = l.begin();
    for(int i = 0; i < l.size(); ++i)
    {
        a[i] = *it;
        ++it;
    }
}
 
int main()
{
    vector<int> a;
    for(int i = 0; i < 4; ++i)
        a.push_back(i);
    printf("a[0] = %d\n", a[0]);
    printf("*a.data() = %d\n", *a.data());
    a.print();
    printf("\n");
    
    a.pop_back();
    *a = 3;
    *(a + 1) = 2;
    a[2] = 1;
    a.print();
    printf("\n");

    printf("for(int i : a)\n");
    for(int i : a)
        printf("%d ", i);
    printf("\n\n");

    printf("vector<int>::iterator i\n");
    for(vector<int>::iterator i = a.begin(); i != a.end(); ++i)
        printf("%d ", *i);
    printf("\n\n");

    a = {1, 2, 3};
    printf("a = {}\n");
    a.print();    
    printf("\n");

    vector<int> b = {1, 2, 3, 4};
    printf("b = {}\n");
    b.print();
}
