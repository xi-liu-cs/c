/* when I saw the int local_histogram[num_threads][num_buckets] from last lecture, this triggered a confusion that I had for arrays allocated this way. In the below program, both a[i * c + j] (in print() function) and *(*(a + i) + j) (in main() function) were used to access the 2d array.  a[i * c + j] shows to me that consecutive memory are used for the 2d array one row after another, *(*(a + i) + j) suggests that there is a metadata array of pointers that point to the start of each row, but if I were to use a metadata array of pointers like the allocation of ary, then if I want to print ary, I need to add r to ary, (print((int *)(ary + r), r, c);), but to print a, I don't need to add this offset (print((int *)a, r, c);). Why it is not needed to add the offset to account for the metadata array of pointers? Where is the metadata array of pointers that point to the start of each row for array int a[r][c]?
*/

#include <stdio.h>
#include <stdlib.h>

void print(int * a, int r, int c)
{
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
            printf("%d ", a[i * c + j]);
        printf("\n");
    }
}

int main()
{
    int r = 4, c = 4,
    cnt = 0;
    int a[r][c];
    printf("a:\n");
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*(a + i) + j) = cnt++;
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
    
    printf("\nprint a:\n");
    print((int *)a, r, c);
    
    printf("\nary:\n");
    int ** ary = malloc(r * sizeof(int *) + r * c * sizeof(int));
    int * ptr = (int *)(ary + r);
    for(int i = 0; i < r; ++i)
        ary[i] = ptr + i * c;
    cnt = 0;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            *(*(ary + i) + j) = cnt++;
            printf("%d ", *(*(ary + i) + j));
        }
        printf("\n");
    }
    printf("\nprint ary:\n");
    print((int *)(ary + r), r, c);
}
