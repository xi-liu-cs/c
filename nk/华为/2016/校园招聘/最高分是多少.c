#include <stdio.h>

void swap(int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int max(int * a, int l, int r)
{
    int max = a[l];
    for(int i = l + 1; i <= r; ++i)
        if(a[i] > max)
            max = a[i];
    return max;
}

int main()
{
    int st, op;
    while(~scanf("%d %d", &st, &op))
    {
        int stu[st];
        for(int i = 0; i < st; ++i) scanf("%d", stu + i);
        for(int i = 0; i < op; ++i)
        {
            int a, b; char c;
            while(scanf("%c %d %d", &c, &a, &b) != 3);
            if(c == 'Q')
            {
                if(a > b) swap(&a, &b);
                printf("%d\n", max(stu, a - 1, b - 1));                   
            }   
            if(c == 'U')
                stu[a - 1] = b;
        }
    }
}
