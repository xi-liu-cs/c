#include "sing_link.h"

int main()
{
    printf("list_init_w(): \n");
    node * n = list_init_w();
    printf("\nprint_list(): \n");
    print_list(n);

    printf("\nlist_init_l(): \n");
    node * n0 = list_init_l();
    printf("\nprint_list(): \n");
    print_list(n0);
}