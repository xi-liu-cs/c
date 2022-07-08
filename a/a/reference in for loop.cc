#include <stdio.h>
#include <vector>
using namespace std;

void print(vector<int> a)
{
    for(auto & a_i : a)
        printf("%d ", a_i);
    printf("\n");
}

int main()
{
    vector<int> a = {1, 2, 3}; 
    for(auto & a_i : a) /* reference */
        a_i = 0;
    printf("a:\n");
    print(a);
    
    vector<int> a2 = {1, 2, 3};
    for(auto a2_i : a2) /* copy */
        a2_i = 0;
    printf("a2:\n");
    print(a2);
}
