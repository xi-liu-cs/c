#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitwise.h"

/* xy = (2^{n/2}x_L + x_R)(2^{n/2}y_L + y_R) 
   = 2^n x_L y_L + 2^{n/2}(x_L y_R + x_R y_L) + x_R y_R
   其中 x_L y_R + x_R y_L 
   = (x_L y_L + x_L y_R + x_R y_L + x_R y_R) - (x_L y_L + x_R y_R)
   = (x_L + x_R)(y_L + y_R) - x_L y_L - x_R y_R
   故 xy 
   =   2^n x_L y_L 
     + 2^{n/2}((x_L + x_R)(y_L + y_R) - x_L y_L - x_R y_R)
     + x_R y_R
   https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-using-divide-and-conquer-algorithm/
*/
int make_equal_length(char ** a, char ** b)
{
    int a_len = strlen(*a), b_len = strlen(*b);
    int diff = abs(a_len - b_len);
    if(a_len < b_len)
    {
        char * a_new = (char *)malloc((b_len + 1) * sizeof(char));
        strcpy(a_new + diff, *a);
        for(int i = 0; i < b_len - a_len; i++)
            *(a_new + i) = '0';
        *a = a_new;
        return b_len;
    }
    else if(b_len < a_len)
    {
        char * b_new = (char *)malloc((a_len + 1) * sizeof(char));
        strcpy(b_new + diff, *b);
        for(int i = 0; i < a_len - b_len; i++)
            *(b_new + i) = '0';
        *b = b_new;
    }
    return a_len;
}

char * add_str(char * a, char * b)
{
    int len = make_equal_length(&a, &b);
    char * ret = (char *)malloc(len * sizeof(char));
    *(ret + len) = '\0';
    int carry = 0;
    for(int i = len - 1; i >= 0; i--)
    {  
        int sum = (*(a + i) == '1') + (*(b + i) == '1') + carry;
        *(ret + i) = sum % 2 ? '1' : '0';
        carry = sum / 2;  
    }
    char * buf;
    if(carry)
    {
        buf = (char *)malloc((len + 1) * sizeof(char));
        strcpy(buf + 1, ret);
        *buf = '1';
        ret = buf;
    }
    return ret;
}

int mult_single_bit(char * a, char * b)
{   return (*a - '0') * (*b - '0');   }

long int multiply(char * a, char * b)
{
    int str_len = make_equal_length(&a, &b);
    if(!str_len) return 0;
    if(str_len == 1) return mult_single_bit(a, b);
    
    int first_half = str_len / 2;
    int sec_half = str_len - first_half;

    char a_L[first_half + 1];
    memcpy(a_L, a, first_half);
    *(a_L + first_half) = '\0';
    char a_R[sec_half + 1];
    memcpy(a_R, a + first_half, sec_half);
    *(a_R + sec_half) = '\0';

    char b_L[first_half + 1];
    memcpy(b_L, b, first_half);
    *(b_L + first_half) = '\0';
    char b_R[sec_half + 1];
    memcpy(b_R, b + first_half, sec_half);
    *(b_R + sec_half) = '\0';
    
    int a_L__b_L = multiply(a_L, b_L);
    int a_R__b_R = multiply(a_R, b_R);
    return (1 << 2 * sec_half) * a_L__b_L
        +  (1 << sec_half) * (multiply(add_str(a_L, a_R), add_str(b_L, b_R)) - a_L__b_L - a_R__b_R)
        +  a_R__b_R;
}

/* outputs the three numbers ab, cd and ad + bc
and uses only three multiplications
(a + c)(b + d) = ab + ad + bc + cd
ad + bc = (a + c)(b + d) - ab - cd */
typedef struct mul
{   int ab, cd, ad_bc;  } mul;

mul * _3mul(int a, int b, int c, int d)
{
    mul * m = (mul *)malloc(sizeof(mul));
    m->ab = a * b; //first multiplication
    m->cd = c * d; //second multiplication
    m->ad_bc = (a + c) * (b + d) - m->ab - m->cd; //third multiplication
    return m;
}

int main()
{
    char * a = "1011";
    char * b = "10101110";
    make_equal_length(&a, &b);
    printf("a = %s\n", a);
    printf("add = %s\n", add_str(a, b));

    int mult = multiply(a, b);
    printf("mult = %d\n", mult);
    print_bin(mult);

    mul * m = _3mul(2, 3, 4, 5);
    printf("m->ab = %d\nm->cd = %d\nm->ad_bc = %d\n", m->ab, m->cd, m->ad_bc);
}