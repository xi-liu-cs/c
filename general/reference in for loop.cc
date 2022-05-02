#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3};
    for(auto & a_i: a) /* reference */
        a_i = 0;
    printf("a:\n");
    for(auto & a_i: a)
        printf("%d ", a_i);
    printf("\n");
    
    int a2[] = {1, 2, 3};
    for(auto a2_i: a2) /* copy */
        a2_i = 0;
    printf("a2:\n");
    for(auto & a2_i: a2)
        printf("%d ", a2_i);
    printf("\n");
}
